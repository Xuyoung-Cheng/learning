#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

extern int n_num;
extern int n_mode;
extern int n_x;
extern int n_y;
extern int n_color;

extern void eraser_shape(int n, int m, int a, int b);
extern void print_mode_shape(int n, int m, int x, int y, int c);

/* get a charater not echo */
int getch()
{
    struct termios tm, tm_old;
    int ch;

    tcgetattr(0, &tm_old);
    cfmakeraw(&tm);
    tcsetattr(0, 0, &tm);
    ch = getchar();
    tcsetattr(0, 0, &tm_old);
    
    return ch;
}

void change_shape()
{
    int m = (n_mode + 1) % 4;

    eraser_shape(n_num, n_mode, n_x, n_y);
    n_mode = m;
    print_mode_shape(n_num, n_mode, n_x, n_y, n_color);
}

void move_left(int n, int m)
{
    eraser_shape(n, m, n_x, n_y);
    n_x -= 2;
    print_mode_shape(n, m, n_x, n_y, n_color);
}

void move_right(int n, int m)
{
    eraser_shape(n, m, n_x, n_y);
    n_x += 2;
    print_mode_shape(n, m, n_x, n_y, n_color);
}

void move_down(int n, int m)
{
    eraser_shape(n, m, n_x, n_y);
    n_y += 1;
    print_mode_shape(n, m, n_x, n_y, n_color);
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
        {
            printf("down\n");
        }
        else if (ch == '\033')
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
                        move_down(n_num, n_mode);
                        break;
                    case 'C':
                        move_right(n_num, n_mode);
                        break;
                    case 'D':
                        move_left(n_num, n_mode);
                        break;
                }
            }
        }
    }
}
