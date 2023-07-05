#include <ntddk.h>
#include<wdm.h>
#include<intrin.h>

#define SMEP_BIT_INDEX 20
#define SMAP_BIT_INDEX 21
#define CR3_ZERO_MASK 0x0000000000000000000000ffffffffff
#define PAGE_DIRECTORY_TABLE_OFFSET 0x028
#define PBYTE char*

#pragma pack(push, 1)
typedef struct virtual_address_parts {
	UINT16 sign_extended;
	UINT16 pml4_offset : 9;
	UINT16 page_directory_pointer_offset : 9;
	UINT16 page_directory_offset : 9;
	UINT16 page_table_offset : 9;
	UINT16 physical_frame_offset : 12;
}virtual_address_parts, * pvirtual_address_parts;
#pragma pack(pop)

void x64_turn_smep_off();

void x64_turn_smep_on();

void x64_turn_smap_off();

void x64_turn_smap_on();

ULONGLONG get_pml4_base_address_cr3();

UINT8 get_pml4_base_address_eprocess();

void parse_virtual_address(PBYTE virtual_address);
