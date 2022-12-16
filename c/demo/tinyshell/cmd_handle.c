#include "cmd_handle.h"
#include "cmd_cp.h"
#include "cmd_ls.h"

#define DEBUG

void init_command_struct(cmd_t *pcmd)
{
	int i;

	memset(pcmd->cmd_name, 0, SZ_NAME);
	for (i = 0; i < SZ_COUNT; i++)
	{
		memset(pcmd->cmd_arg_list, 0, SZ_ARG);
	}
	pcmd->cmd_arg_count = 0;
}

void print_command_struct(cmd_t *pcmd)
{
	int i;

	printf("-------------------\n");
	printf("[DEBUG] cmd name: < %s >\n", pcmd->cmd_name);
	printf("[DEBUG] cmd arg count: < %d >\n", pcmd->cmd_arg_count);
	printf("[DEBUG] cmd arg list: ");

	for (i = 0; i < pcmd->cmd_arg_count; i++)
	{
		printf(" %s ", pcmd->cmd_arg_list[i]);
	}
	printf("\n");
	printf("-------------------\n");
}

int cmd_parse(char *cmd, cmd_t *pcmd)
{
	char *p_cmd_name = NULL;
	char *p_cmd_arg = NULL;
	int index = 0;

	if (cmd == NULL || pcmd == NULL)
		return -1;

	p_cmd_name = strtok(cmd, " ");
#ifdef DEBUG
	printf("[DEBUG]: cmd name: < %s >\n", p_cmd_name);
#endif
	strcpy(pcmd->cmd_name, p_cmd_name);

	for (;;)
	{
		p_cmd_arg = strtok(NULL, " ");
		if (p_cmd_arg == NULL)
			break;
		strcpy(pcmd->cmd_arg_list[index++], p_cmd_arg);
	}

	pcmd->cmd_arg_count = index;

	return 0;
}

int cmd_dispatch(cmd_t *pcmd)
{

	if (pcmd == NULL)
		return -1;

	if (strcmp(pcmd->cmd_name, "ls") == 0)
	{
#ifdef DEBUG
		printf("ls command handle\n");

		cmd_ls_execute(pcmd);
#endif
	}
	else if (strcmp(pcmd->cmd_name, "cp") == 0)
	{
#ifdef DEBUG
		printf("cp command handle\n");
#endif
		cmd_cp_execute(pcmd);
	}
}

int cmd_execute(char *cmd)
{
	cmd_t command;
	int ret;

	if (cmd == NULL)
		return -1;

#ifdef DEBUG
	printf("[DEBUG]: cmd:< %s >\n", cmd);
#endif

	init_command_struct(&command);

	ret = cmd_parse(cmd, &command);
	if (ret == -1)
		return -1;
#ifdef DEBUG
	print_command_struct(&command);
#endif

	ret = cmd_dispatch(&command);
	if (ret == -1)
		return -1;

	return 0;
}
