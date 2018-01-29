#include <stdio.h>
#include <Windows.h>

#define CHAR_OPTIONS 265

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Please use: <Program> <P> (P - The file path)");
		getchar();
		return 0;
	}

	HANDLE hFile = CreateFile(
		argv[1],						// filename
		GENERIC_READ | GENERIC_WRITE,	// access
		0,								// shared mode
		NULL,							// security attributes
		OPEN_EXISTING ,					// creation disposition
		NULL,							// flags
		NULL// template file
	);

	if(NULL == hFile)
	{
		printf("Error - File Not Found\n");
		return 4;
	}

	HANDLE hMFile = CreateFileMapping(
		hFile,							// file handle
		NULL,							// security attributes
		PAGE_READWRITE,					// protect
		0,								// file max size high
		0,								// file max size low
		NULL							// map name
	);

	if(NULL == hMFile)
	{
		printf("Error - Could not map file\n");
		return 2;
	}

	DWORD dwFileSize = GetFileSize(hFile, NULL);
	size_t occurrences[CHAR_OPTIONS] = {0};
	unsigned char placement[CHAR_OPTIONS];

	char *lpMapAddress = MapViewOfFile(
		hMFile,							// map object
		FILE_MAP_ALL_ACCESS,			// access
		0,								// offset high
		0,								// offset low
		0								// bytes to map
	);

	size_t index = 0;
	
	// Scan file
	for(size_t i = 0; i < dwFileSize; i++)
	{
		unsigned char current = lpMapAddress[i];
		if(0 == occurrences[current])
		{
			placement[index++] = current;
		}

		occurrences[current]++;
	}

	index = 0;

	// Reorder file
	for(size_t i = 0; i < dwFileSize;)
	{
		unsigned char current = placement[index];
		
		for(size_t j = 0; j < occurrences[current]; j++,i++)
		{
			lpMapAddress[i] = current;
		}

		index++;
	}


	UnmapViewOfFile(lpMapAddress);
	CloseHandle(hMFile);
	CloseHandle(hFile);

	return 0;
}