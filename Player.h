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
	//���캯��--ͨ��base��ȡ���;��ʼ��������ɫ
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

	void			getTeam();			//�����Ҷ���
	void			getCrosshairID();	//������׼��
	int				getHealth();		//������Ѫ��
	void			getGlowIndex();		//���glowindex;
	void			makeGlow(int i);	//��glow;

public:
	//��ʼ��--��ȡ�����׼��
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
