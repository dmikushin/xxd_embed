#include "xxd.h"

#include <cstdio>

int main(int argc, char* argv[])
{
	printf("%s", (*xxd)["resource"].first);
	return 0;
}

