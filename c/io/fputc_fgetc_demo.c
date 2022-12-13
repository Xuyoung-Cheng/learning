#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char ch;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		return -1;
	}

	fp = fopen(argv[1], "r+");

	if (NULL == fp) {
		perror("Error fopen(): ");
		return -1;
	}

	for (;;) {
		ch = fgetc(fp);

		if (ch == EOF)
			break;
		fputc(ch, stdout);
	}

	fclose(fp);

	return 0;
}
