#include "Main.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

void algorithm()
{
	maml::CSourceFile source;

	if (source.read_from_file_at_path("Source.txt"))
	{
		for (int i = 0; i < source.m_bytes; i++)
		{
			char c = source.m_buffer[i];

			std::cout << c;
		}
	}
}

int main(int argc, char* argv[])
{
	algorithm();

	_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
	return _CrtDumpMemoryLeaks();
}