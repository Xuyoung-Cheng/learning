#ifndef __CMD_LS_H__
#define __CMD_LS_H__

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <dirent.h>
#include <stdbool.h>
#include <time.h>

#include "cmd_handle.h"

#define SZ_LS_NAME 64
#define SZ_LS_PERMISSION 10
#define SZ_LS_TIME 32
#define SZ_LS_LINK_CONTENT 64

#define DEBUG

typedef struct file_attribute
{
	struct stat f_attr_stat_info;

	char f_attr_type;
	char f_attr_uname[SZ_LS_NAME];
	char f_attr_gname[SZ_LS_NAME];
	char f_attr_mtime[SZ_LS_TIME];
	char f_attr_permission[SZ_LS_PERMISSION];
	char f_attr_name[SZ_LS_NAME];
	char f_attr_link_content[SZ_LS_LINK_CONTENT];
} file_attr_t;

extern int cmd_ls_execute(cmd_t *pcmd);
int cmd_list_directory(const char *dirpath);
int get_file_attr(file_attr_t *pattr,
				  const char *path,
				  const char *filename,
				  bool islink);
void make_path_ls(char *path, const char *dirpath, const char *filename);
void show_file_attributes(file_attr_t *pattr);

int get_file_type_ls(file_attr_t *pattr);
int get_file_permission(file_attr_t *pattr);
void get_file_uname(file_attr_t *pattr);
void get_file_gname(file_attr_t *pattr);
void get_file_last_modify_time(file_attr_t *pattr);

#endif
