#include <stdlib.h>
#include <stdio.h>

#define N 20
#define UPPERBOUND 10

int a[N];
int histogram[UPPERBOUND] = {0};

void gen_random(int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound; /* rand() % (upper_bound - lower_bound + 1) + lower_bound; */
}

int howmany(int value)
{
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

void print_histogram()
{
	int i, end_flag;

	for (i = 0; i < UPPERBOUND; i++)
		printf("%d  ", i);
	printf("\n");

	while (1) {
		end_flag = 0;
		printf("\n");
		for (i = 0; i < UPPERBOUND; i++) {
			if (histogram[i] > 0) {
				printf("%c  ", '*');
				histogram[i]--;
			} else {
				printf("%c  ", ' ');
				end_flag++;
			}
		}
		printf("\n");

		if (end_flag == UPPERBOUND) 
			break; 
	} 
}

int main(void)
{
	int i;

	gen_random(UPPERBOUND);
	printf("value\thow many\n");
	for (i = 0; i < 10; i++) {
		printf("%d\t%d\n", i, howmany(i));
	}

	for (i = 0; i < N; i++)
		histogram[a[i]]++;

	print_histogram();

	return 0;
}
