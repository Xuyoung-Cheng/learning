#include <stdio.h>

extern void print_mode_shape(int n, int m, int x, int y, int c);

int main(int argc, char const *argv[])
{
    printf("\033[2J");
    int x = 6;
    int y = 6;
    int k = 0;
    int i = 0;
    for (k = 0; k < 7; k++)
    {
        for (i = 0; i < 4; i++)
        {
            print_mode_shape(k, i, x, y, 43);
            x += 12;
        }

        x = 6;
        y += 4;

        printf("\n");
        getchar();
    }
    printf("\033[?25h");
    return 0;
}
