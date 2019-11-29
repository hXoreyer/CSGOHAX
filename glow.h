#pragma once
#include <thread>
#include "funBase.h"
#include "Player.h"
class glow : public funBase
{
public:
	glow();
	~glow();
	virtual void run(const char* context);
	static DWORD WINAPI makeglow(LPVOID lpParam);
public:
	HANDLE handle;
};

