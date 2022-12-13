#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *pref = NULL;

	char buf[64] = {0};

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
		pref = fgets(buf, sizeof(buf), fp);

		if (pref == NULL)
			break;
		fputs(buf, stdout);
	}

	fclose(fp);

	return 0;
}
