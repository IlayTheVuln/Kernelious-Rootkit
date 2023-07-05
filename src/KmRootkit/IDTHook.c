#include "IDTHook.h"


idtr get_idt_base_address()
{
	idtr idtr;
	__sidt((pidtr)&idtr);
	return idtr;

}

void iterate_intrrupt_descriptors(pidtr idtr_ptr)
{
	pinterrupt_descriptor idt_entry = (pinterrupt_descriptor)idtr_ptr->base_address;
	long idt_entries_number = (idtr_ptr->limit + 1) / IDT_ENTRY_SIZE;
	for (int i = 0; i < idt_entries_number; i++)
	{
		PBYTE isr_ptr = 0;
		memcpy(((PBYTE)&isr_ptr), (PBYTE)&idt_entry->offset_1, 2);
		memcpy(((PBYTE)&isr_ptr) + 2, (PBYTE)&idt_entry->offset_2, 2);
		memcpy((PBYTE)&isr_ptr + 4, (PBYTE)&idt_entry->offset_3, 4);
		DbgPrint("ISR is located at: %p\n",isr_ptr);
		                                            
		idt_entry++;
	}
	                      
}

idt_entry_offsets parse_hooking_function(PBYTE hooking_function)
{
	UINT16 offset_1 = (UINT16)hooking_function;
	UINT16 offset_2 = (UINT16)((ULONG64)hooking_function >> (8 * 2));
	UINT32 offset_3 = (UINT32)((ULONG64)hooking_function >> (8 * 4));
	idt_entry_offsets idt_entry_offsets = { .offset_1 = offset_1, .offset_2 = offset_2, .offset_3 = offset_3 };
	
	return idt_entry_offsets;

}

PBYTE get_isr_by_interrupt_number(pidtr idtr_ptr, ULONG interrupt_number)
{
	pinterrupt_descriptor idt_entry = (pinterrupt_descriptor)idtr_ptr->base_address + interrupt_number;
	PBYTE isr_ptr = 0;
	memcpy(((PBYTE)&isr_ptr), (PBYTE)&idt_entry->offset_1, 2);
	memcpy(((PBYTE)&isr_ptr) + 2, (PBYTE)&idt_entry->offset_2, 2);
	memcpy((PBYTE)&isr_ptr + 4, (PBYTE)&idt_entry->offset_3, 4);

	return isr_ptr;

} 

void hook_idt_entry(PBYTE hooking_function, pidtr idtr_ptr, ULONG interrupt_number)
{
	pinterrupt_descriptor idt_entry = (pinterrupt_descriptor)(idtr_ptr->base_address) + interrupt_number;
	idt_entry_offsets idt_entry_offsets = parse_hooking_function(hooking_function);

	idt_entry->offset_1 = idt_entry_offsets.offset_1;
	idt_entry->offset_2 = idt_entry_offsets.offset_2;
	idt_entry->offset_3 = idt_entry_offsets.offset_3;

}



