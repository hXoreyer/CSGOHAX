#ifndef PLAYER_H
#define PLAYER_H
#include "sdk.h"

extern ProcMem Mem;
extern DWORD   clientDll;
class Player
{
public:
	DWORD	base;
	int		team;
	int		crosshairID;
	DWORD	glowIndex;
	DWORD	glowobj;
	bool	isDormant;
public:
	//构造函数--通过base获取玩家;初始化三种颜色
	Player(DWORD _base)
		:base(_base),team(0),crosshairID(0),glowIndex(0)
	{
		red.R = 255;
		red.G = 0;
		red.B = 0;
		red.A = 255;

		blue.R = 0;
		blue.G = 0;
		blue.B = 255;
		blue.A = 255;

		green.R = 0;
		green.G = 255;
		green.B = 0;
		green.A = 255;

		glowobj = 0;
		isDormant = true;
	}

	void			getTeam();			//获得玩家队伍
	void			getCrosshairID();	//获得玩家准心
	int				getHealth();		//获得玩家血量
	void			getGlowIndex();		//获得glowindex;
	void			makeGlow(int i);	//画glow;

public:
	//初始化--获取队伍和准心
	inline void init()
	{
		getTeam();
		getCrosshairID();
	}

	/*
	void outputMem()
	{
		cout << Mem.getPid() << endl;
	}
	*/
private:
	struct game_glow
	{
		float R;
		float G;
		float B;
		float A;
		unsigned char padding[0x16];
		bool renderWhenOccluded = true;
		bool renderWhenUnoccluded = false;
	};
	game_glow red;
	game_glow blue;
	game_glow green;
};


#endif // !PLAYER_H
