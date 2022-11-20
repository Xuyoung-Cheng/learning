#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* background: yellow; font color: red */
    printf("\033[43;31m");
    printf("Hello world!\n");
    printf("\033[0m");

    return 0;
}
