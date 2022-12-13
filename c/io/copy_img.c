#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src = NULL;
	FILE *dst = NULL;
	int buf[64] = {0};
	size_t s;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <pathname> <pathname>\n", argv[0]);
		return -1;
	}

	src = fopen(argv[1], "r");
	if (src == NULL) {
		perror("Error fopen(): ");
		return -1;
	}
	dst = fopen(argv[2], "w+");
	if (dst == NULL) {
		perror("Error fopen(): ");
		return -1;
	}

	while((s = fread(buf, sizeof(int), 64, src)) > 0) {
		fwrite(buf, sizeof(int), 64, dst);
	}
	
	fclose(src);
	fclose(dst);

	return 0;
}
