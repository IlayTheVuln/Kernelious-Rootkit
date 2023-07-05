#pragma warning (disable: 4100)
#pragma warning (disable : 4820 4619 4668)
#include "SSDTHook.h"

char original_nt_function_bytes[12] = { 0 }; 
PBYTE nt_version_function_ptr = NULL;

int get_syscall_number(PBYTE function_pointer)
{
	return (int)*(PINT32)((PBYTE)( ((PUINT32)function_pointer) + 5) + 1);
}

PBYTE get_function_base_address(PCWSTR func_name)
{
	UNICODE_STRING func_unicode_string = { 0 };
	RtlInitUnicodeString(&func_unicode_string, func_name);

	return (PBYTE)MmGetSystemRoutineAddress(&func_unicode_string);
}


PBYTE get_ntoskrnl_base_address()
{
	PVOID ntoskrnl_base_address;
	UNICODE_STRING pc_to_file_header_string;

	RtlInitUnicodeString(&pc_to_file_header_string, L"RtlPcToFileHeader");
	prtl_pc_to_file_header rtl_pc_to_file_header_function = (prtl_pc_to_file_header)MmGetSystemRoutineAddress(&pc_to_file_header_string);
	rtl_pc_to_file_header_function((PVOID)&ZwQueryKey, &ntoskrnl_base_address);

	return (PBYTE)ntoskrnl_base_address;
}

BOOLEAN is_address_start_of_pattern(PBYTE address)
{
	char pattern[] = PATTERN;
	for (int i = 0; i < sizeof(pattern); i++)
	{
		if ( (char)* (pattern + i) !=  (char)* ((PBYTE)(address + i)))
		{
			return FALSE;
		}
	}
	return TRUE;
}

PBYTE get_ki_systen_service_start(PBYTE ntoskrnl_image_base)
{
	int i = 0;
	while (TRUE)
	{
		if (is_address_start_of_pattern((PBYTE)(ntoskrnl_image_base +i)))
		{
			return ntoskrnl_image_base + i;
		}
		i++;
	}
}


PBYTE get_sdt_address(PBYTE ki_systen_service_start_address)
{
	PBYTE lea_r10_sdt_instruction_pointer = (PBYTE)(ki_systen_service_start_address + SDT_SYMBOL_OFFSET);
	int* offset_pointer = (int*)(lea_r10_sdt_instruction_pointer + 3);
	int offset = *offset_pointer;

	PBYTE next_instruction_irp_value = lea_r10_sdt_instruction_pointer + 7;
	PBYTE sdt_address = next_instruction_irp_value + offset;

	return sdt_address;
}


PLONG64 get_ssdt_base_address(PBYTE sdt_address)
{
	psystem_descriptor_table sdt = (psystem_descriptor_table)sdt_address;
	return sdt->system_service_descriptor_table;

}

PBYTE get_nt_version_function(PLONG64 ssdt_base_address, int syscall_number)
{
	int ssdt_entry_offset = *((int*)((PBYTE)ssdt_base_address + 4*syscall_number));
	nt_version_function_ptr = (PBYTE)((PBYTE)ssdt_base_address + (ssdt_entry_offset>>4));
	return nt_version_function_ptr;
}

void write_trampoline(PBYTE hooking_function, PBYTE hooked_memory)
{
	DbgPrint("Building Trampoline...\n");
	memcpy(original_nt_function_bytes, hooked_memory, 12);
	*(hooked_memory) = 0x48;
	*(hooked_memory + 1) = 0xb8;
	PBYTE func_ptr = hooking_function;
	memcpy(hooked_memory + 2, &func_ptr, sizeof(func_ptr));
	*(hooked_memory + 10) = 0xff;
	*(hooked_memory + 11) = 0xe0;
}


void restore_nt_function(PBYTE nt_version_function)
{
	memcpy(nt_version_function, original_nt_function_bytes, 12);
}

BOOLEAN is_valid_code_cave_code_segment(PBYTE start_address)
{
	for (int i = 0; i < SHELLCODE_SIZE; i++)
	{
		if ( *(start_address + i) != 0x90 && *(start_address + i) != 0xcc)
		{
			return FALSE;
		}
	}
	return TRUE;
}


BOOLEAN is_valid_code_cave_data_segment(PBYTE start_address)
{
	PUINT64 zero_memory_segment = (PUINT64)start_address;
	for (int i = 0; i < 10; i++)
	{
		if (*(zero_memory_segment + i) != 0)
		{
			return FALSE;
		}
	}
	return TRUE;
}

PBYTE scan_for_code_cave(PBYTE start_address, ULONG limit)
{
	PBYTE current_address = start_address;
	PBYTE last_address = (PBYTE)((start_address - SHELLCODE_SIZE - 80) + limit);
	while (current_address < last_address)
	{
		if (is_valid_code_cave_code_segment(current_address))
		{
			DbgPrint("valid code cave found in code segment: %p", current_address);
			return current_address;
		}
		else if (is_valid_code_cave_data_segment(current_address))
		{
			DbgPrint("valid code cave found in data segment: %p", current_address);
			return current_address;

		}
		current_address++;

	}
	return NULL;
}



BOOLEAN hook_nt_function(PCWSTR hooked_function_name, PBYTE hooking_function)
{
	PBYTE nt_function_address = get_nt_version_function(get_ssdt_base_address(get_sdt_address(get_ki_systen_service_start(get_ntoskrnl_base_address()))), get_syscall_number(get_function_base_address(hooked_function_name)));
	write_trampoline(nt_function_address, hooking_function);
	
	return TRUE;
}

UINT32 calcultae_ssdt_entry(PBYTE ssdt_base_address, PBYTE code_cave_address, UINT32 args_number)
{

	UINT32 rva_to_code_cave = (UINT32)(code_cave_address - ssdt_base_address);
	UINT32 valid_ssdt_entry = rva_to_code_cave << 4; 
	valid_ssdt_entry |= (args_number - ARGUMENTS_VIA_REGISTERS_COUNT);
	DbgPrint("ssdt entry: %x \n", valid_ssdt_entry);
	return valid_ssdt_entry;


}


BOOLEAN hook_ssdt_with_code_cave(PCWSTR hooked_function_name, PBYTE hooking_function)
{
	PBYTE ssdt_base_address = get_ssdt_base_address(get_sdt_address(get_ki_systen_service_start(get_ntoskrnl_base_address())));
	int syscall_number = get_syscall_number(get_function_base_address(hooked_function_name));
	get_nt_version_function((PULONG64)ssdt_base_address, syscall_number);

	PUINT32 ssdt_entry_ptr = (PUINT32)(ssdt_base_address + (SSDT_ENTRY_SIZE * syscall_number));
	PBYTE code_cave_address = scan_for_code_cave(ssdt_base_address, MAX_DISTANCE_RVA);
	if (code_cave_address == NULL)
	{
		return FALSE;
	}

	UINT32 fixed_ssdt_entry = calcultae_ssdt_entry(ssdt_base_address, code_cave_address, 11);
	*(ssdt_entry_ptr) = fixed_ssdt_entry;

	SIZE_T patched_bytes = 0X1000;
	ULONG old_protection = 0;
	NTSTATUS page_protection_status = ZwProtectVirtualMemory(PsGetCurrentProcessId(), (PVOID)code_cave_address, &patched_bytes, PAGE_EXECUTE_READWRITE, &old_protection);
	write_trampoline(hooking_function, code_cave_address);

	return TRUE;
}