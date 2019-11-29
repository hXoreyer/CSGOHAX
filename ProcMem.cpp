#include "ProcMem.h"

//Process������ʵ��
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

//Module������ʵ��
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
	//�򿪵�ǰ���̵ķ�������
	int hRet = OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken);

	if (hRet)
	{
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		//ȡ������Ȩ�޵�LUID
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		//�����������Ƶ�Ȩ��
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);

		CloseHandle(hToken);
	}
}