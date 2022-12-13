#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src = NULL;
	FILE *dst = NULL;
	char ch;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <pathname> <pathname>\n", argv[0]);
		return -1;
	}

	src = fopen(argv[1], "r+");
	if (src == NULL) {
		perror("Error fopen(src): ");
		return -1;
	}
	dst = fopen(argv[2], "w+");
	if (dst == NULL) {
		perror("Error fopen(dst): ");
		return -1;
	}

	for (;;) {
		ch = fgetc(src);

		if (ch == EOF)
			break;
		fputc(ch, dst);
	}
	
	fclose(src);
	fclose(dst);

	return 0;
}
