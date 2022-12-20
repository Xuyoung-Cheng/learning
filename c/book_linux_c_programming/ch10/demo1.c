#include <stdio.h>

#define CAP 100

int add_range(int low, int high)
{
	int i = 0, sum = 0;

	for (i = low; i <= high; i++)
		sum += i;

	return sum;
}

int main(void)
{
	int result[CAP];
	result[0] = add_range(1, 10);
	result[1] = add_range(1, 100);
	printf("result[0]=%d\nresult[1]=%d\n", result[0], result[1]);
	return 0;
}
