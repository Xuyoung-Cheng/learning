#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src = NULL;
	FILE *dst = NULL;
	char *pref = NULL;

	char buf[64] = {0};
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <pathname> <pathname>\n", argv[0]);
		return -1;
	}

	src = fopen(argv[1], "r+");
	if (src == NULL) {
		perror("Error fopen(): ");
		return -1;
	}
	dst = fopen(argv[2], "w+");
	if (dst == NULL) {
		perror("Error fopen(): ");
		return -1;
	}

	for (;;) {
		pref = fgets(buf, sizeof(buf), src);

		if (pref == NULL)
			break;
		fputs(buf, dst);
	}
	
	fclose(src);
	fclose(dst);

	return 0;
}
