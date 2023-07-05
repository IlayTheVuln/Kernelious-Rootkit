#pragma once
#include <Ntddk.h>
#include <wdm.h>
#include <intrin.h>

#pragma pack(push,1)
typedef struct gdt_entry {
	UINT16 limit_1;
	UINT16 base_1;
	UCHAR base_2;
	UCHAR access_byte;
	UCHAR limit_2 : 4;
	UCHAR flags : 4;
	UCHAR base_3;
	UINT32 base_4;
	UINT32 reserved;
}gdt_entry, *pgdt_entry;
#pragma pop

