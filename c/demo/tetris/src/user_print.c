#include "user_print.h"

void print_mode_shape(int n, int m, int x, int y, int c)
{
    int i = 0;
    int xx = x;
    int yy = y;

    for (i = 0; i < 16; i++)
    {
        if (i != 0 && i % 4 == 0)
        {
            yy += 1;
            xx = x;
        }

        if (shape[n][m][i] == 1)
        {
            printf("\033[%d;%dH\033[%dm[]\033[0m", yy, xx, c);
        }
        xx += 2;
    }

    fflush(NULL);
}

void erase_last_shape(int n, int m, int a, int b)
{
    int i = 0;
    int xx = a;
    int yy = b;

    for (i = 0; i < 16; i++)
    {
        if (i != 0 && i % 4 == 0)
        {
            yy += 1;
            xx = a;
        }

        if (shape[n][m][i] == 1)
        {
            printf("\033[%d;%dH  \033[0m", yy, xx);
        }
        xx += 2;
    }

    fflush(NULL);
}

void print_next_shape()
{
    erase_last_shape(next_num, next_mode, next_x, next_y);

    next_num = random() % 7;
    next_mode = random() % 4;
    next_color = random() % 7 + 40;

    print_mode_shape(next_num, next_mode, next_x, next_y, next_color);
    fflush(NULL);
}

void store_current_shape()
{
    int m_line = dynamic_y - 6;
    int m_column = dynamic_x - 12;
    int i = 0;

    for (i = 0; i < 16; i++)
    {
        if (i != 0 && i % 4 == 0)
        {
            m_line++;
            m_column = dynamic_x - 12;
        }

        if (shape[dynamic_num][dynamic_mode][i] == 1)
        {
            matrix[m_line][m_column] = dynamic_color;
            matrix[m_line][m_column + 1] = dynamic_color;
        }

        m_column += 2;
    }
}

int judge_shape(int n, int m, int x, int y)
{
    int m_line = y - 6;
    int m_column = x - 12;
    int i = 0;

    for (i = 0; i < 16; i++)
    {
        if (i != 0 && i % 4 == 0)
        {
            m_line++;
            m_column = x - 12;
        }

        if (shape[n][m][i] == 1)
        {
            if (matrix[m_line][m_column] != 0)
                return 1;
        }
        m_column += 2;
    }

    return 0;
}

void init_new_shape()
{
    dynamic_num = next_num;
    dynamic_mode = next_mode;
    dynamic_color = next_color;

    dynamic_x = init_x;
    dynamic_y = init_y;

    print_mode_shape(next_num, next_mode, dynamic_x, dynamic_y, dynamic_color);
}

void print_matrix()
{
    int i, j;

    for (i = 0; i < 24; i++)
    {
        for (j = 0; j < 28; j += 2)
        {
            if (matrix[i][j] == 0)
                printf("\033[%d;%dH  \033[0m", i + 6, j + 12);
            else
                printf("\33[%d;%dH\33[%dm[]\33[0m",i + 6,j + 12,matrix[i][j]);
        }
    }
}

void print_score_level()
{
    printf("\33[%d;%dH分数:%d\33[0m",score_y,score_x,user_score);
    printf("\33[%d;%dH等级:%d\33[0m",level_y,level_x,user_level);
    fflush(NULL);
}
