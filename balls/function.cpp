#include "stdafx.h"
#include "const.h"

#ifdef _WIN32
#undef main
#endif


int main()
{
	CWindow window;
	window.ShowFixedSize({ WIDTH, HEIGHT });
	window.DoGameLoop();

	return 0;
}