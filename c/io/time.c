#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	time_t t;
	struct tm *ptm = NULL;
	FILE *fp = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		return -1;
	}

	fp = fopen(argv[1], "w+");
	if (fp == NULL) {
		perror("Error fopen(): ");
		return -1;
	}

	time(&t);
	ptm = localtime(&t);
	fprintf(fp, "<%d-%d-%d %d:%d:%d>"
		,ptm->tm_year + 1900
		,ptm->tm_mon + 1
		,ptm->tm_mday
		,ptm->tm_hour
		,ptm->tm_min
		,ptm->tm_sec);
	
	fclose(fp);

	return 0;
}

