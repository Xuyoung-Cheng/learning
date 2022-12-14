#ifndef __CMD_CP_H__
#define __CMD_CP_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include "cmd_handle.h"

#define SZ_PATH 64
#define SZ_BUFFER 1024

enum file_type
{
	FT_DIR = 0,
	FT_FILE = 1,
	FT_ERROR = 2,
	FT_UNKNOWN = 3,
};

typedef struct cp_file_info
{
	enum file_type src_ftype;
	char src_path[SZ_PATH];
	char dest_path[SZ_PATH];
} cp_file_info_t;

extern int cmd_cp_execute(cmd_t *pcmd);
int cmd_cp_parse_path(cp_file_info_t *pfileinfo, cmd_t *pcmd);
int cmd_cp_parse_type(cp_file_info_t *pfileinfo);
enum file_type get_file_type(const char *path);
int cmd_cp_dispatch(cp_file_info_t *pfileinfo);
int cmd_cp_file(const char *src, const char *dest);
int cmd_cp_dir(const char *src, const char *dest);
void make_path(cp_file_info_t *pinfo, const char *src, const char *dest, const char *filename);

#endif
