#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* clear */
    printf("\e[2J");
    printf("\e[20;14H");
    printf("\e[43;31m");
    printf("Hello world!\n");
    // printf("\033[?25l");
    printf("\e[0m");

    return 0;
}
