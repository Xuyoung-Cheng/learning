#include <stdio.h>

void newline(void)
{
	printf("\n");
}

void threeline(void)
{
	newline();
	newline();
	newline();
}

int main(void)
{
	printf("First Line.\n");
	threeline();
	printf("Second Line.\n");
	return 0;
}
