#include <stdio.h>

int main(void)
{
	/* --- Declaration start --- */
	/* Definition */
	char firstlatter;
	int hour, minute;

	/* Initialization */
	char lastlatter = 'z';
	/* --- Declaration end --- */

	
	/* Assignment statement */
	firstlatter = 'a';
	hour = 11, minute = 59;

	/* use variables, read the value */
	printf("Current time is %d: %d\n", hour, minute);

	return 0;
}
