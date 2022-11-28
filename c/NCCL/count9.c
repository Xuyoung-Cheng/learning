/*
 * count9.c	- sumary how many digit from 1 to 100 
 * 
 * Author: simon cheng <xxx@163.com>
 * Create Date: 2022-11-28
 * Revision v0.1
 * 	+ function count
 */

#include <stdio.h>

/* 
 * count - calculate how many digit in number 
 * 
 * 	@num: the number from 1 to 100
 * 	@digit: digit can be [0, 1, 2, 3, ... , 9]
 *
 * 	return value: the counter of digit in this number
 * 
 * example:
 * 	num : 99, digit: 9
 * 	return 2
 */
int count(int num, int digit)
{
	int counter = 0;

	do {
		if (num % 10 == digit) {
			counter++;	
		}

		num /= 10;
	} while (num != 0);

	return counter;
}

int main(void)
{
	int sum = 0, i = 0;

	printf("count 9 from 1 to 100.\n");

	for (i = 1; i <= 100; i++)
	{
		sum += count(i, 9);
	}

	printf("sum = %d\n", sum);

	return 0;
}
