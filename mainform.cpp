#include "mainform.h"

MainForm::MainForm()
{
	bkey.bglow = false;
	bkey.btrigger = false;
	fun = new Function();
}
MainForm::~MainForm()
{
	delete fun;
}

void MainForm::EventLoop()
{
	while (true)
	{
		if (KEYDOWN(VK_F6))
		{
			while (!KEYUP(VK_F6));
			if (!bkey.bglow)
				fun->run("glow", "run");
			else
				fun->run("glow", "stop");
			bkey.bglow = !bkey.bglow;
		}
		if (KEYDOWN(VK_F7))
		{
			while (!KEYUP(VK_F7));
			if (!bkey.btrigger)
				fun->run("trigger", "run");
			else
				fun->run("trigger", "stop");
			bkey.btrigger = !bkey.btrigger;
		}
		Sleep(100);
	}
}