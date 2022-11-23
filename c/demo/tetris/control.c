#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

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
                        printf("up\n");
                        break;
                    case 'B':
                        printf("down\n");
                        break;
                    case 'C':
                        printf("right\n");
                        break;
                    case 'D':
                        printf("left\n");
                        break;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    key_control();
    return 0;
}
