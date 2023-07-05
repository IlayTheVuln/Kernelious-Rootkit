#include<wdm.h>
#include<ntddk.h>
#include <intrin.h>
#define IDT_ENTRY_SIZE 16
#define PBYTE char*

#pragma pack(push, 1)
typedef struct idtr {
	UINT16 limit;
	PBYTE base_address;
}idtr, *pidtr;


typedef struct interrupt_descriptor {
	UINT16 offset_1;
	UINT16 segment_selector;
	char ist : 3;
	char reserved_1 : 5;
	char gate_type : 4;
	char reserved_2 : 1;
	char dpl : 2;
	char p : 1;
	UINT16 offset_2;
	UINT32 offset_3;
	UINT32 reserved_3;
}interrupt_descriptor, *pinterrupt_descriptor;

#pragma pack(pop)

typedef struct idt_entry_offsets {
	UINT16 offset_1;
	UINT16 offset_2;
	UINT32 offset_3;
}idt_entry_offsets, * pidt_entry_offsets;


idtr get_idt_base_address();
void iterate_intrrupt_descriptors(pidtr idtr_ptr);
PBYTE get_isr_by_interrupt_number(pidtr idtr_ptr, ULONG interrupt_number);
idt_entry_offsets parse_hooking_function(PBYTE hooking_function);
void hook_idt_entry(PBYTE hooking_function, pidtr idtr_ptr, ULONG interrupt_number);