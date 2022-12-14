#include <stdio.h>
#include <string.h>

#include "cmd_handle.h"

#define SZ_CMD 64

int main(int argc, char *argv[])
{
	char command[SZ_CMD] = {0};

	for (;;) {
		printf("tinyshell> ");
		fgets(command, SZ_CMD, stdin);

		command[strlen(command) -1] = '\0';

		if (strncmp(command, "quit", 4) == 0) {
			printf("GoodBye\n");
			break;
		}

		cmd_execute(command);	
	}

	return 0;
}
