#include "PageTableHook.h"

void x64_turn_smep_off()
{
	_disable();
    __writecr4(__readcr4() & (~(1 << SMEP_BIT_INDEX)));
	_enable();
}

void x64_turn_smep_on()
{
	_disable();
	__writecr4(__readcr4() | (1<<SMEP_BIT_INDEX));
	_enable();
}

void x64_turn_smap_off()
{
	_disable();
	__writecr4(__readcr4() & (~(1 << SMAP_BIT_INDEX)));
	_enable();
}

void x64_turn_smap_on()
{
	_disable();
	__writecr4(__readcr4() | (1 << SMAP_BIT_INDEX));
	_enable();
}

ULONGLONG get_pml4_base_address_cr3()
{
	ULONGLONG CR3 = __readcr3();
	CR3 >>= 12;
	DbgPrint("cr3 shred: %p", CR3);
	CR3 &= CR3_ZERO_MASK;
	DbgPrint("CR3 is: %p\n", CR3);
	return CR3;
}


UINT8 get_pml4_base_address_eprocess()
{
	PEPROCESS current_process_eprocess = IoGetCurrentProcess();
	PKPROCESS current_process_kprocess = (PKPROCESS)current_process_eprocess;
	DbgPrint("kprocess is at %p\n", current_process_kprocess);
	UINT64 pml4_base_address = *((PUINT64)(((PBYTE)current_process_kprocess + PAGE_DIRECTORY_TABLE_OFFSET)));
	DbgPrint("pml4 is at: %p\n", pml4_base_address);
	return pml4_base_address;

}
