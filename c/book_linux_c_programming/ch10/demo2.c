#include <stdio.h>

#define LEN 5

int main(void)
{
	int sum = 0, i = 0;
	char input[LEN];

	while (1) {
		sum = 0;
		scanf("%s", input);

		for (i = 0; input[i] != '\0'; i++) {
			if (i > (LEN-1) || input[i] < '0' || input[i] > '9') {
				printf("Invalid input!\n");
				sum = -1;
				break;
			}
			sum = sum*10 + input[i] - '0';
		}
		printf("input=%d\n", sum);
	}
	return 0;
}
