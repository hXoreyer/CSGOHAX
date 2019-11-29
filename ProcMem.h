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
	//读成员函数----参数:地址 ----返回值:读取后的值
	template <class cData>
	cData Read(DWORD address)
	{
		cData cRead;
		ReadProcessMemory(hProcess, (LPVOID)address, &cRead, sizeof(cData), NULL);
		return cRead;
	}

	//写成员函数----参数:地址和值
	template <class cData>
	void Write(DWORD address, cData val)
	{
		WriteProcessMemory(hProcess, (LPVOID)address, &val, sizeof(cData), NULL);
	}

	void	 deBugPrivilege();					//进程提权
	bool	 Process(const char* processName);	//通过此函数获得进程的pid和Process
	DWORD	 Module(const char* moduleName);	//通过此函数获得某模块的地址

	DWORD	 getPid()							//获取pid
	{
		return dwPid;
	}
};

#endif // !PROCMEM_H
