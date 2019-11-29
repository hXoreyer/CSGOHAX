#include "ProcMem.h"

//Process函数的实现
bool ProcMem::Process(const char* processName)
{
	deBugPrivilege();
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);

	do
	{
		if (strcmp(ProcEntry.szExeFile, processName) == 0)
		{


			dwPid = ProcEntry.th32ProcessID;
			CloseHandle(hPID);


			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
			cout << "Find success:  " << ProcEntry.szExeFile << endl;
			return true;
		}
	}while (Process32Next(hPID, &ProcEntry));
	CloseHandle(hPID);
	return false;
}

//Module函数的实现
DWORD ProcMem::Module(const char* moduleName)
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPid);
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);


	do
	{
		if (strcmp(mEntry.szModule, moduleName) == 0)
		{
			CloseHandle(hModule);
			cout << "Find success:  " << mEntry.szModule << endl;
			return (DWORD)mEntry.modBaseAddr;
		}
	} while (Module32Next(hModule, &mEntry));

	cout << "MODULE: Process Platform Invalid\n";
	return 0;
}

void ProcMem::deBugPrivilege()
{
	HANDLE hToken = NULL;
	//打开当前进程的访问令牌
	int hRet = OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken);

	if (hRet)
	{
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		//取得描述权限的LUID
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		//调整访问令牌的权限
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);

		CloseHandle(hToken);
	}
}