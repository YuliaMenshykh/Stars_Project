#include "pch.h"
#include "Application/Application.h"



int _tmain(int argc, _TCHAR* argv[])
{
	Application app;
	app.Init();
	app.EntryPoint();
	return 0;
}

