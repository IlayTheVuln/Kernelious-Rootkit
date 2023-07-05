#include "Utilities.h"

void kernel_sleep(long time_interval_sec)
{
	LARGE_INTEGER time_interval;
	time_interval.QuadPart = (INT64)((INT64)(-1*time_interval_sec)*HUN_NANO_SEC_TO_SEC);
	KeDelayExecutionThread(KernelMode, FALSE, &time_interval);
}

PVOID kernel_malloc(size_t size)
{
	return  ExAllocatePool2(NonPagedPool, size,'yali');

}

void kernel_free(PVOID buffer_ptr)
{
	ExFreePool(buffer_ptr);

}
BOOLEAN kernel_compare_unicode_strings(PWCHAR s1, PWCHAR s2)
{
	PWCHAR first = s1;
	PWCHAR second = s2;
	while (*first != L'\0')
	{
		if (*first != *second)
		{
			return  FALSE;
		}
		first++;
		second++;
	}
	return TRUE;
}
BOOLEAN kernel_compare_memory(PBYTE s1, PBYTE s2)
{
	for (size_t i = 0; i < strlen(s1); i++)
	{
		if (*(s1 + i) != *s2)
		{
			return FALSE;
		}
	}
	return TRUE;

}
void kernel_memory_move(PVOID dst, PVOID src, size_t size)
{
	memmove(dst, src, size);
}
 