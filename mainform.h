#pragma once
#include "function.h"
#define KEYDOWN(KEYNAME) ((GetAsyncKeyState(KEYNAME) & 0x8000 ) ? 1 : 0)
#define KEYUP(KEYNAME) ((GetAsyncKeyState(KEYNAME) & 0x8000 ) ? 0 : 1)
class MainForm
{
public:
	MainForm();
	~MainForm();

	void EventLoop();
private:
	struct key
	{
		bool bglow;
		bool btrigger;
	};
	Function *fun;
	key bkey;
};
