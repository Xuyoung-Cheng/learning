#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include "user_print.h"
#include "user_control.h"

/*
012345678901234567890123456789012345678901234567890123456789
1                                                        
2                                                        
3                                                        
4                                                        
5         |||||||||||||||||||||||||||||||||||||||||||||||
6         ||            []              ||             ||
7         ||            []              ||             ||
8         ||            [][]            ||    [][]     ||
9         ||                            ||      [][]   ||
0         ||                            ||             ||
1         ||                            ||             ||
2         ||                            |||||||||||||||||
3         ||                            ||             ||
4         ||                            ||             ||
5         ||                            ||             ||
6         ||                            ||             ||
7         ||                            ||             ||
8         ||                            ||   score:    ||
9         ||                            ||             ||
0         ||                            ||             ||
1         ||                            ||             ||
2         ||                            ||   level:    ||
3         ||                            ||             ||
4         ||                            ||             ||
5         ||                            ||             ||
6         ||                            ||             ||
7         ||                            ||             ||
8         ||                            ||             ||
9         ||                            ||             ||
0         |||||||||||||||||||||||||||||||||||||||||||||||
1
*/

void print_start_ui()
{
    int i;

    printf("\033[2J");
    for (i = 0; i < 47; i++)
    {
        printf("\033[%d;%dH\033[43m \033[0m", 5, i + 10);
        printf("\033[%d;%dH\033[43m \033[0m", 30, i + 10);
    }

    for (i = 0; i < 26; i++)
    {
        printf("\033[%d;%dH\033[43m  \033[0m", i + 5, 10);
        printf("\033[%d;%dH\033[43m  \033[0m", i + 5, 40);
        printf("\033[%d;%dH\033[43m  \033[0m", i + 5, 56);
    }

    for (i = 0; i < 17; i++)
    {
        printf("\033[%d;%dH\033[43m \033[0m", 12, 40 + i);
    }

    printf("\033[%d;%dHscore:\033[0m", score_y, score_x);
    printf("\033[%d;%dHlevel:\033[0m", level_y, level_x);

    fflush(NULL);
    return;
}

void init_game_ui()
{
    print_start_ui();

    getch();

    srand(time(NULL));
    dynamic_num = random() % 7;
    dynamic_mode = random() % 4;
    dynamic_color = random() % 7 + 40;
    dynamic_x = init_x;
    dynamic_y = init_y;

    print_mode_shape(dynamic_num, dynamic_mode, dynamic_x, dynamic_y, dynamic_color);
    print_next_shape();

    printf("\033[?25l");
}

int get_matrix_result(int n_line)
{
    int i = 0;

    if (n_line < 0)
        return 1;

    for (i = 0; i <28; i++)
    {
        if (matrix[n_line][i] != 0)
            return 1;
    }

    return 0;
}

int judge_end_game()
{
    int i = 0;
    int n_line = 23;

    for (i = 0; i < 24; i++)
    {
        int no_zero = get_matrix_result(n_line);
        if (no_zero != 0)
            n_line--;
        else
            return 0;
    }

    return 1;
}

void sig_handler(int signum)
{
    move_down(dynamic_num, dynamic_mode);

    if (judge_end_game())
    {
        game_over();
        recover_attribute();
        exit(0);
    }
}

int main(int argc, char const *argv[])
{
    init_game_ui();

    signal(SIGALRM, sig_handler);
    alarm_us(tm); // custom timers

    key_control();
    return 0;
}
