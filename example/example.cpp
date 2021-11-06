#include "xxd.h"

#include <cstdio>

int main(int argc, char* argv[])
{
	printf("%s", xxd::get("resource"));
	return 0;
}

