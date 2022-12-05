#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    /* fd - file descriptor */
    write(0, "hello world\n", 12);
    return 0;
}