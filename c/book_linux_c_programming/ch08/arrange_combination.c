#include <stdio.h>

#define N 5
#define M 4

int a[N], b[M];


void print_arr(int *a)
{
	int i;
	for (i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int i, int offset)
{
	if (i == offset)
		return;
	a[i] ^= a[offset];
	a[offset] ^= a[i];
	a[i] ^= a[offset];
}

void arrange(int offset) {
	int i;
	if (offset == M) {
		print_arr(a);
		return;
	}

	for (i = offset; i < N; i++) {
		swap(i, offset);
		arrange(offset+1);
		swap(i, offset);
	}
}

void comb(int n, int m)
{
	int i;
	if (m == 0) {
		print_arr(b);
		return;
	}

	for (i = n-1; i>= 0; i--) {
		b[m-1] = a[i];
		comb(i, m-1);
	}
}


int main(void)
{
	int i;
	
	for (i = 0; i < N; i++)
		a[i] = i+1;

	arrange(0);
	comb(N, M);

	return 0;
}
