#ifndef __USER_PRINT_H__
#define __USER_PRINT_H__

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>

extern int tm;

extern int score_x;
extern int score_y;
extern int level_x;
extern int level_y;
extern int user_score;
extern int user_level;

extern int init_x;
extern int init_y;

extern int next_num;
extern int next_mode;
extern int next_color;
extern int next_x;
extern int next_y;

extern int dynamic_num;
extern int dynamic_mode;
extern int dynamic_color;
extern int dynamic_x;
extern int dynamic_y;

extern int shape[7][4][18];
extern int matrix[24][28];extern int user_score;

extern void print_mode_shape(int n, int m, int x, int y, int c);
extern void print_next_shape();
extern void erase_last_shape(int n, int m, int a, int b);

extern void store_current_shape();
extern int judge_shape(int num, int mode, int x, int y);
extern void init_new_shape();

extern void print_matrix();
extern void print_score_level();

#endif