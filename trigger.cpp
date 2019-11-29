#include "trigger.h"
#include <string>
#include <iostream>
trigger::trigger()
{
}
trigger::~trigger()
{
}
void trigger::run(const char* context)
{
	if (!strcmp(context, "run"))
	{
		cout << "trigger run\n";
		handle = CreateThread(NULL, 0, &(this->maketrigger), NULL, 0, NULL);
	}
	else if (!strcmp(context, "stop"))
	{
		cout << "trigger stop\n";
		TerminateThread(handle, 0);
		CloseHandle(handle);
	}
	
}

DWORD WINAPI trigger::maketrigger(LPVOID lpParam)
{
	Player localPlayer(Mem.Read<DWORD>(clientDll + offsets::m_localPlayer));
	Player *entity;
	while (true)
	{
		localPlayer.init();
		localPlayer.getCrosshairID();
		entity = new Player(Mem.Read<DWORD>(clientDll + offsets::m_entityList + (localPlayer.crosshairID - 1) * 0x10));
		entity->init();
		int hp = entity->getHealth();
		if (entity->team != localPlayer.team && hp > 0)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
			mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
			Sleep(1000);
		}
	}
	return 0;
}