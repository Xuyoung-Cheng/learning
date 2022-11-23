#include <stdio.h>

extern void init_shape();
extern void key_control();

int main(int argc, char const *argv[])
{
    printf("\033[2J");
    printf("\033[?25l");
    
    init_shape();
    key_control();

    printf("\033[?25h");

    return 0;
}
