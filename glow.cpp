#include "glow.h"
#include <string>
#include <iostream>
glow::glow()
{
}
glow::~glow()
{
}
void glow::run(const char* context)
{
	if (!strcmp(context, "run"))
	{
		cout << "glow run\n";
		handle = CreateThread(NULL, 0, &(this->makeglow), NULL, 0, NULL);
	}
	else if (!strcmp(context, "stop"))
	{
		cout << "glow stop\n";
		TerminateThread(handle,0);
		CloseHandle(handle);
	}
	
}

DWORD WINAPI glow::makeglow(LPVOID lpParam)
{
	Player localPlayer(Mem.Read<DWORD>(clientDll + offsets::m_localPlayer));
	Player* player;
	while (true)
	{
		
		localPlayer.init();
		for (int i = 0; i <= 64; i++)
		{
			player = new Player(Mem.Read<DWORD>(clientDll + offsets::m_entityList + i * 0x10));
			player->init();
			if (player->team == localPlayer.team)
			{
				delete player;
				continue;
			}
			player->getGlowIndex();
			if (player->isDormant == false)
			{
				int hp = player->getHealth();
				//cout << "hp = " << hp << endl;
				if (hp > 0 && hp <= 30)
				{
					player->makeGlow(2);
				}
				else if (hp > 30 && hp <= 60)
				{
					player->makeGlow(1);
				}
				else if (hp > 60 && hp <= 100)
				{
					player->makeGlow(0);
				}
			}
			delete player;
		}
		Sleep(10);
	}
	return 0;

}