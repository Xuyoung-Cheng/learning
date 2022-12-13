#include <stdio.h>

int main(void)
{
	fprintf(stdout, "[stdout] Hello, Linux io"); // cache

	fflush(stdout);
	fprintf(stderr, "[stderr] Hello, Linux io");
	while(1);
	return 0;
}
