#include <stdio.h>

int main(void)
{
	int hour, minute;

	hour = 11, minute = 59;

	/* expression: operand + operator */
	/* hour * 60 + minute */
	int total_minute = hour * 60 + minute;
	printf("%d:%d is %d minutes after 00:00\n", hour, minute, total_minute);
	/* left value, right value */

	/* c / is rounding to zero */
	printf("%d hours and %d percent of an hour\n", hour, minute * 100 /60);
	printf("%d and %f hours\n", hour, minute / 60.0);

	/* exercise: int/int ceiling */
	printf("---- exercise ----\n");
	printf("%d / %d = %d, ceiling: %d\n", 17, 4, 17/4, (17+4-1)/4);

	return 0;
}
