#include "function.h"
Function::Function()
{
	con["glow"] = new glow();
	con["trigger"] = new trigger();
}

Function::~Function()
{
	delete con["glow"];
	delete con["trigger"];
}

void Function::run(const char* context,const char* stat)
{
	con[context]->run(stat);
}