#include <stdio.h>

int main(void)
{
    int i = 0;
    int sum = 0;

    printf("sum evens from 1 to 100\n");

    for (i = 0; i <= 100; i++)
    {
        if (i % 2 == 1)
            continue;
        sum += i;
    }
    /*
    for (i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
            sum += i;
    }
    */

    /* 
    for (i = 0; i <= 100; i += 2) 
        sum += i;
    */

    printf("sum = %d\n", sum);

    return 0;
}

