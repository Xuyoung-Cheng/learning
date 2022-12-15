#include <stdio.h>

int main(void)
{
	int a[5] = {4,3,2,1,};
	int b[5];
	int i;

	for (i = 0; i < 5; i++) {
		b[i] = a[i];
	}

	for (i = 0; i < 5; i++) {
		printf("a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
	}

	return 0;
}
