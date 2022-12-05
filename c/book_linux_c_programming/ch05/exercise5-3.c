#include <stdio.h>

/* Euclid */
int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	return GCD(b, a%b);
}

int main(void)
{
	int a = 1, b = -2;
	printf("%d\n", GCD(a, b));
	return 0;
}
