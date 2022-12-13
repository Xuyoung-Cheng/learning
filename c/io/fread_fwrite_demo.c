#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	float numbers[5] = {1.1, 1.2, 1.3, 1.4, 1.5};
	float result[5] = {0};
	size_t witems = 0, ritems = 0;
	int i = 0;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname> \n", argv[0]);
		return -1;
	}

	fp = fopen(argv[1], "r+");

	if (fp == NULL) {
		perror("Error fopen(): ");
		return -1;
	}

	witems = fwrite(numbers, sizeof(float), 5, fp);
	if (witems != 5) {
		perror("Error fwrite(): ");
		return -1;
	}
	
	fseek(fp, 0, SEEK_SET);
	ritems = fread(result, sizeof(float), 5, fp);
	if (ritems != 5) {
		perror("Error fread(): ");
		return -1;
	}

	for (i = 0; i < 5; i++) {
		printf(" %f ", result[i]);
	}
	printf("\n");

	fclose(fp);
	return 0;
}
