#include "SYSENTERHook.h"

ULONGLONG original_lstar = 0;

sysenter_msrs get_sysenter_msrs()
{
    sysenter_msrs sysenter_msrs;
    sysenter_msrs.STAR = __readmsr(STAR_NUMBER);
    sysenter_msrs.CSTAR = __readmsr(CSTAR_NUMBER);
    sysenter_msrs.LSTAR = __readmsr(LSTAR_NUMBER);
    sysenter_msrs.SFMASK = __readmsr(SFMASK_NUMBER);

    return sysenter_msrs;
}

void print_sysenter_msrs()
{
    sysenter_msrs sysenter_msrs = get_sysenter_msrs();
    DbgPrint("msrs status=>> STAR: %p, CSTAR: %p, LSTAR: %p, SFMASK: %p\n", sysenter_msrs.STAR, sysenter_msrs.CSTAR, sysenter_msrs.LSTAR, sysenter_msrs.SFMASK);
}

void hook_sysenter_instruction(PBYTE hooking_function)
{
    _disable();
    original_lstar = __readmsr(LSTAR_NUMBER);
    DbgPrint("before hook:\n");
    USHORT group_count, group_array = 0;
    HANDLE current_process = (HANDLE)ZwCurrentProcess();
    
    //__writemsr(LSTAR_NUMBER, (ULONGLONG)hooking_function);
    _enable();
}

void hooking_function_sysenter()
{
    PULONGLONG current_lstar = __readmsr(LSTAR_NUMBER);
    DbgPrint("current lstar is: %llu\n", current_lstar);
    __writemsr(LSTAR_NUMBER, original_lstar);
    DbgPrint("reached to the hooking fucking function :)\n");
}
