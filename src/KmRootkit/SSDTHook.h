#pragma once
#include<ntddk.h>
#include<wdm.h>
#include <ntimage.h>
#include <intrin.h>
#define PBYTE char*
#define SDT_SYMBOL L"KeServiceDescriptorTable"
#define SSDT_ENTRY_SIZE 4
#define PATTERN {0x48,0x89,0xa3,0x90,0x00,0x00,0x00,0x8b,0xf8,0xc1,0xef,0x07};
#define PATTERN_SIZE 12
#define MAX_DISTANCE_RVA 0xfffffff
#define SHELLCODE_SIZE 12	
#define SDT_SYMBOL_OFFSET 0X14
#define ARGUMENTS_VIA_REGISTERS_COUNT 4

PBYTE nt_version_function_ptr;

typedef NTSYSAPI PVOID (*prtl_pc_to_file_header)(PVOID PcValue, PVOID* BaseOfImage), rtl_pc_to_file_header(PVOID PcValue, PVOID* BaseOfImage);


typedef struct system_descriptor_table
{
	PLONG64 system_service_descriptor_table;
	PLONG64 null_padding1;
	PLONG64 null_padding2;
	PLONG64 params;
}system_descriptor_table, *psystem_descriptor_table;




int get_syscall_number(PBYTE function_pointer);

PBYTE get_function_base_address(PCWSTR func_name);

PBYTE get_ntoskrnl_base_address();

BOOLEAN is_address_start_of_pattern(PBYTE address);

PBYTE get_ki_systen_service_start(PBYTE ntoskrnl_image_base);

PBYTE get_sdt_address(PBYTE ki_systen_service_start_address);

PLONG64 get_ssdt_base_address(PBYTE sdt_address);

PBYTE get_nt_version_function(PLONG64 ssdt_base_address, int syscall_number);


void write_trampoline(PBYTE hooking_function, PBYTE hooked_memory);

void restore_nt_function(PBYTE nt_version_function);

BOOLEAN hook_ssdt_with_code_cave(PCWSTR hooked_function_name, PBYTE hooking_function);

extern NTSTATUS ZwProtectVirtualMemory(IN HANDLE ProcessHandle, IN PVOID* BaseAddress, IN SIZE_T* NumberOfBytesToProtect, IN ULONG NewAccessProtection, OUT PULONG OldAccessProtection);