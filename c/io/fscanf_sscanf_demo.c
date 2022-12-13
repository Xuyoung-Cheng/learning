#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	int numa = 0, numb = 0, numc = 0;
	char buf[64] = "10-20-30";

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		return -1;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Error fopen(): ");
		return -1;
	}

	fscanf(fp, "%d-%d-%d", &numa, &numb, &numc);
	printf("numa = %d, numb = %d, numc = %d\n", numa, numb, numc);

	
	numa = 0, numb = 0, numc = 0;
	sscanf(buf, "%d-%d-%d", &numa, &numb, &numc);
	printf("numa = %d, numb = %d, numc = %d\n", numa, numb, numc);

	return 0;
}
