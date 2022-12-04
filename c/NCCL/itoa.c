#include <stdio.h>

#if 0
void swap(int a, int b)
{
	a ^= b;
	b ^= a;
	a ^= b;
	
	return;
}
#endif

#define SWAP(a, b) 	\
do {			\
	a ^= b;		\
	b ^= a;		\
	a ^= b;		\
} while(0)

void reverse(char buf[], int i)
{
	int j;
	
	for (j = 0; j < i/2; j++) {
		SWAP(buf[j], buf[i-1-j]);
	}

	return;
}

void itoa(int num, char buf[])
{
	int i;

	i = 0;
	do {
		buf[i++] = num % 10 + '0';
		num /= 10;
	} while (num != 0);
	buf[i] = '\0';

	reverse(buf,i);	

	return;
}

int main(void)
{
	int num = 123;
	char buf[10];

	printf("input a number : ");
	scanf("%d", &num);
	printf("num = %d\n", num);

	itoa(num, buf);

	printf("buf = %s\n", buf);

	return 0;
}
