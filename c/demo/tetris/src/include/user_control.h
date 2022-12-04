#ifndef __USER_CONTROL_H__
#define __USER_CONTROL_H__

#include <stdio.h>
#include <termios.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

extern int getch();
extern void alarm_us(int n);
extern void key_control();
extern void fall_down();
extern int move_left(int n, int m);
extern int move_right(int n, int m);
extern int move_down(int n, int m);
extern int change_shape();
extern void game_over();
extern void recover_attribute();
extern void destory_cond_line();

#endif