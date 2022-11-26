#include "user_print.h"
#include "user_control.h"

struct termios tm_old;

int getch()
{
    struct termios tm;
    int ch;

    tcgetattr(0, &tm_old);
    cfmakeraw(&tm);
    tcsetattr(0, 0, &tm);
    ch = getchar();
    tcsetattr(0, 0, &tm_old);

    return ch;
}

void recover_attribute()
{
    tcsetattr(0, 0, &tm_old);
}

void alarm_us(int n)
{
    struct itimerval value;
    
    value.it_value.tv_sec = 0;
    value.it_value.tv_usec = n;
    value.it_interval.tv_sec = 0;
    value.it_interval.tv_usec = n;

    setitimer(ITIMER_REAL, &value, NULL);
}

void fall_down()
{
    int ret;

    while(1)
    {
        ret = move_down(dynamic_num, dynamic_mode);
        if (ret == 1)
            return;
    }
}

int move_left(int n, int m)
{
    if (dynamic_x <= 12)
        return 1;

    if (judge_shape(n, m, dynamic_x - 2, dynamic_y))
        return 1;

    erase_last_shape(n, m, dynamic_x, dynamic_y);
    dynamic_x -= 2;
    print_mode_shape(n, m, dynamic_x, dynamic_y, dynamic_color);
    return 0;
}

int move_right(int n, int m)
{
    if (dynamic_x + 2 * (4 - shape[n][m][16]) -1 >= 39)
        return 1;

    if (judge_shape(n, m, dynamic_x + 2, dynamic_y))
        return 1;

    erase_last_shape(n, m, dynamic_x, dynamic_y);
    dynamic_x += 2;
    print_mode_shape(n, m, dynamic_x, dynamic_y, dynamic_color);
    return 0;
}

int move_down(int num, int mode)
{
    if (dynamic_y + (4 - shape[num][mode][17]) - 1 >= 29 ||
        judge_shape(num, mode, dynamic_x, dynamic_y + 1))
    {
        store_current_shape();
        init_new_shape();
        destory_cond_line();
        print_next_shape();
        return 1;
    }

    erase_last_shape(num, mode, dynamic_x, dynamic_y);
    dynamic_y++;
    print_mode_shape(num, mode, dynamic_x, dynamic_y, dynamic_color);

    return 0;
}

int change_shape()
{
    int m = (dynamic_mode + 1) % 4;

    if (dynamic_x + 2 * (4 - shape[dynamic_num][m][16]) - 1 > 39)
        return 1;

    if (dynamic_y + 2 * (4 - shape[dynamic_num][m][17]) - 1 > 29)
        return 1;

    erase_last_shape(dynamic_num, dynamic_mode, dynamic_x, dynamic_y);
    dynamic_mode = m;
    print_mode_shape(dynamic_num, dynamic_mode, dynamic_x, dynamic_y, dynamic_color);
    return 0;
}

void destory_cond_line()
{
    int i, j, k;
    int flag = 0;

    for (i = 0; i < 24; i++)
    {
        flag = 1;
        for (j = 1; j < 28; j++)
        {
            if (matrix[i][j] == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            user_score += 10;
            if (user_score % 100 == 0)
            {
                user_level++;
                tm /= 2;
                alarm_us(tm);
            }

            for (k = i; k > 0; k--)
            {
                for (j = 0; j < 28; j++)
                    matrix[k][j] = matrix[k - 1][j];
                print_matrix();
                print_score_level();
            }
        }
    }
}

void key_control()
{
    int ch;

    while (1)
    {
        ch = getch();
        if (ch == 'q' || ch == 'Q')
            break;
        else if (ch == '\r')
            fall_down();
        else if (ch == '\33')
        {
            ch = getch();
            if (ch == '[')
            {
                ch = getch();
                switch (ch)
                {
                case 'A':
                    change_shape();
                    break;
                case 'B':
                    move_down(dynamic_num, dynamic_mode);
                    break;
                case 'D':
                    move_left(dynamic_num, dynamic_mode);
                    break;
                case 'C':
                    move_right(dynamic_num, dynamic_mode);
                    break;
                default:
                    break;
                }
            }
        }
    }

    game_over();
}

void game_over()
{
    printf("\33[32;9H************ Game Over***********************************\33[0m");
    printf("\33[25h");
    printf("\n\n");
}