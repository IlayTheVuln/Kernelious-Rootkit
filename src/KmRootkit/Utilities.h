#pragma once
#include<ntddk.h>
#include<wdm.h>
#include <ntimage.h>
#include <intrin.h>
#define PBYTE char*
#define HUN_NANO_SEC_TO_SEC 10000000

void kernel_sleep(long time_interval_sec);
PVOID kernel_malloc(size_t size);
BOOLEAN kernel_compare_memory(PBYTE s1, PBYTE s2);
BOOLEAN kernel_compare_unicode_strings(PWCHAR s1, PWCHAR s2);
void kernel_memory_move(PVOID src, PVOID dst, size_t size);

