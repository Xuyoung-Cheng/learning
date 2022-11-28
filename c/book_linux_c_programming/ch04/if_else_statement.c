#include <stdio.h>

void print_parity(int x)
{
	if (x % 2 == 0)
		printf("x is even.\n");
	else
		printf("x is odd.\n");
}

void print_ten_and_bit(int num)
{
	printf("ten: %d, bit: %d\n", (num/10) % 10, num % 10);
}

int main(void)
{
	int x = 1;

	print_parity(17);
	print_parity(18);

	if (x > 0)
		printf("x is positive.\n");
	else if (x < 0)
		printf("x is negtive.\n");
	else
		printf("x is zero.\n");

	x = -1;
	if (x > 0) {
		printf("x is positive.\n");
	} else {
		if (x < 0)
			printf("x is negtive.\n");
		else
			printf("x is zero.\n");
	}

	/* exercise */
	int num = 120;
	int bit = num % 10;
	int ten = (num/10) % 10;

	print_ten_and_bit(num);

	return 0;
}
