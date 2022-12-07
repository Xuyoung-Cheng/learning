#include <stdio.h>

int main(void)
{
	int counter = 0;
	int i = 1;
	int num = 0;

	while (i < 100) {
		num = i;
		while (num != 0) {
			if (num % 10 == 9)
				counter += 1;
			num /= 10;
		}
		i += 1;
	}

	printf("%d\n", counter);
	
	return 0;
}
