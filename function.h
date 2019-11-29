#pragma once
#include <iostream>
#include <map>
#include "funBase.h"
#include "glow.h"
#include "trigger.h"
using namespace std;
class Function
{
private:
	map<const char*, funBase*> con;
public:
	Function();
	~Function();
	void run(const char* context, const char* stat);
};

