#ifndef PROCMEM_H
#define PROCMEM_H

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <sstream>
using namespace std;
class ProcMem
{
public:
	HANDLE hProcess;
	DWORD  dwPid;
public:
	//����Ա����----����:��ַ ----����ֵ:��ȡ���ֵ
	template <class cData>
	cData Read(DWORD address)
	{
		cData cRead;
		ReadProcessMemory(hProcess, (LPVOID)address, &cRead, sizeof(cData), NULL);
		return cRead;
	}

	//д��Ա����----����:��ַ��ֵ
	template <class cData>
	void Write(DWORD address, cData val)
	{
		WriteProcessMemory(hProcess, (LPVOID)address, &val, sizeof(cData), NULL);
	}

	void	 deBugPrivilege();					//������Ȩ
	bool	 Process(const char* processName);	//ͨ���˺�����ý��̵�pid��Process
	DWORD	 Module(const char* moduleName);	//ͨ���˺������ĳģ��ĵ�ַ

	DWORD	 getPid()							//��ȡpid
	{
		return dwPid;
	}
};

#endif // !PROCMEM_H
