#ifndef FUNBASE_H
#define FUNBASE_H
#include <Windows.h>
class funBase
{
public:
	funBase();
	virtual void run(const char* context) = 0;
	virtual ~funBase();
};


#endif // !FUNBASE_H

