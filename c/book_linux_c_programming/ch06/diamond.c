#include <stdio.h>

void diamond(int n, char c)
{
	int i = 0;
	int j = 0;

	if (n % 2 == 0) {
		printf("error: need a odd number.\n");	
		return;
	}

	for (i = 1; i <= n/2+1; i++) {
		for (j = 1; j <= n/2+1-i; j++)
			printf("\t");
		for (j = 1; j <= 2*i-1; j++)
			printf("%c\t", c);
		printf("\n");
	}

	for (i = n/2; i >= 1; i--) {
		for (j = 1; j <= n/2+1-i; j++)
			printf("\t");
		for (j = 1; j <= 2*i-1; j++)
			printf("%c\t", c);
		printf("\n");
	}

	return;
}

int main(void)
{
	diamond(5, '+');

	return 0;
}
