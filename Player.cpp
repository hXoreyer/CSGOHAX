#include "Player.h"
void Player::getTeam()
{
	team = Mem.Read<int>(base + offsets::m_teamNum);
}

void Player::getCrosshairID()
{
	crosshairID = Mem.Read<int>(base + offsets::m_corsshairID);
}

int Player::getHealth()
{
	return Mem.Read<int>(base + offsets::m_health);
}

void Player::getGlowIndex()
{
	glowobj = Mem.Read<DWORD>(clientDll + offsets::m_glowObject);
	isDormant = Mem.Read<bool>(base + offsets::m_bDormant);
	glowIndex = Mem.Read<DWORD>(base + offsets::m_glowIndex);
}

void Player::makeGlow(int i)
{
	game_glow co;
	switch (i)
	{
	case 0:
		memcpy(&co, &green, sizeof(game_glow));
		break;
	case 1:
		memcpy(&co, &blue, sizeof(game_glow));
		break;
	case 2:
		memcpy(&co, &red, sizeof(game_glow));
		break;
	default:
		break;
	}
	Mem.Write<float>(glowobj + (glowIndex * 0x38 + 0x4), co.R);
	Mem.Write<float>(glowobj + (glowIndex * 0x38 + 0x8), co.G);
	Mem.Write<float>(glowobj + (glowIndex * 0x38 + 0xC), co.B);
	Mem.Write<float>(glowobj + (glowIndex * 0x38 + 0x10), co.A);
	Mem.Write<bool>(glowobj + (glowIndex * 0x38 + 0x24), co.renderWhenOccluded);
	Mem.Write<bool>(glowobj + (glowIndex * 0x38 + 0x25), co.renderWhenUnoccluded);
}
