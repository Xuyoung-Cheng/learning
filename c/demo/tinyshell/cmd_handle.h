#ifndef __CMD_HANDLER_H__
#define __CMD_HANDLER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ_NAME  8
#define SZ_COUNT 2 
#define SZ_ARG   32

typedef struct command
{
	char cmd_name[SZ_NAME];
	char cmd_arg_list[SZ_COUNT][SZ_ARG];
	int  cmd_arg_count;
} cmd_t;

extern int cmd_execute(char *cmd); /* command executes entry point. */
void init_command_struct(cmd_t *pcmd);
void print_command_struct(cmd_t *pcmd);
int cmd_parse(char *cmd, cmd_t *pcmd);
int cmd_dispatch(cmd_t *pcmd);

#endif
