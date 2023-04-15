#include "Main.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>


void algorithm()
{
	maml::SInit init;
	maml::init(init);

	maml::scan_file("Source.txt");

	maml::terminate();
}


int main(int argc, char* argv[])
{
	algorithm();

	_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
	return _CrtDumpMemoryLeaks();
}