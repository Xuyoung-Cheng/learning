#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname> \n", argv[0]);
		return -1;
	}

	fp = fopen(argv[1], "w+");

	if (fp == NULL) {
		perror("Error fopen(): ");
		return -1;
	}

	fclose(fp);
	return 0;
}
