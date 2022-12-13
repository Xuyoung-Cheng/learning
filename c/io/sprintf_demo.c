#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	int numa = 10, numb = 20, numc = 30;
	char buf[64] = {0};
	
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		return -1;
	}

	fp = fopen(argv[1], "w+");
	if (fp == NULL) {
		perror("Error fopen(): ");
		return -1;
	}

	fprintf(fp, "%d-%d-%d\n", numa, numb, numc);
	sprintf(buf, "%d-%d-%d\n", numa, numb, numc);
	
	printf("buffer : %s\n", buf);

	fclose(fp);
	
	return 0;
}
