#include <stdio.h>
#include <math.h>

int main(void)
{
	int i;
	int num = 100;
	int max;

	printf("find the max prime from 1 to 100.\n");
	for (num = 1; num <= 100; num+=2) {
		int tmp = sqrt(num);

		for (i = 2; i < tmp; i++) {
			if (num % i == 0) {
#if DEBUG				
				printf("%d is a prime\n", num);
#endif
				break;
			}
		}
		
		if (i == tmp) {
#if DEBUG
			printf("%d is not a prime\n", num);
#endif
			max = num;
		}
	}
	
	printf("max prime is %d.\n", max); 
	
	return 0;
}
