#include <stdio.h>

/* global variable hour, minute */
int hour = 23, minute = 59;

void print_time(int hour, int minute)
{
	/* local variable hour, minute in print_time function */
	printf("%d:%d\n", hour, minute);
}

int main(void)
{
	print_time(hour, minute);
	return 0;
}
