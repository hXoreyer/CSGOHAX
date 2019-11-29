#pragma once
#include <thread>
#include "funBase.h"
#include "Player.h"
class trigger : public funBase
{
public:
	trigger();
	~trigger();
	virtual void run(const char* context);
	static DWORD WINAPI maketrigger(LPVOID lpParam);
public:
	HANDLE handle;
};

