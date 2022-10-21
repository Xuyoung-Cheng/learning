#include <stdio.h>

int global = 200;
extern _start;

int main(void)
{
    int local = 100;

    printf("_start is %p\n", &_start);
    printf("\n");

    printf("hello, world.\n");
    printf("local = %d\n", local);
    printf("local = %x\n", local);
    printf("local = %#x\n", local);
    printf("&local = %p\n", &local);
    printf("\n");
    
    printf("global = %d\n", global);
    printf("global = %x\n", global);
    printf("global = %#x\n", global);
    printf("&global = %p\n", &global);
    printf("\n");
    
    printf("main = %p\n", main);

    return 0;
}