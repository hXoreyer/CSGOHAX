//#include "Player.h"
#include "mainform.h"
#include <vector>

extern ProcMem Mem;
extern DWORD   clientDll;
int main()
{
	cout << "waiting for csgo.exe\n";
	while (!Mem.Process("csgo.exe"));
	clientDll = Mem.Module("client_panorama.dll");

	cout << "F6 run glow\n F7 run trigger\n";
	MainForm *mainform = new MainForm();
	mainform->EventLoop();
	delete mainform;
	
	return 0;
}