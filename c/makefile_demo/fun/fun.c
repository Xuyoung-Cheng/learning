#include "global.h"
#include "fun.h"

int global = 20;

int fun()
{
	printf("a = %d\n", a);
	return 0;
}

void print_value()
{
	printf("global = %d\n", global);
}

