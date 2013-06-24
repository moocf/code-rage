#include "stdafx.h"
#include "problem2.h"

int _tmain(int argc, char* argv[])
{
	argc = 3;
	argv = new char*[3];
	argv[0] = "";
	argv[1] = "input2.txt";
	argv[2] = "output2.txt";
	exec(argc, argv);
	return 0;
}

