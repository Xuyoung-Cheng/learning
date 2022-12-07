#include <stdio.h>

int fib(int n)
{
	int a = 0;
	int b = 1;
	int c = 0;
	int i = 0;

	for (i = 0; i < n; i++) {
		c = b + a;
		a = b;
		b = c;
	}

	return c;
}

int main(void)
{
	printf("%d\n", fib(8));
	return 0;
}
