#include <stdio.h>

int main(void)
{
    int counter = 0;

    printf("count your fingers\n");

    counter = 0;
    while (counter < 10)
    {
        counter++;
        printf("counter = %d\n", counter);
    }

    /*
    counter = 1;
    while (counter <= 10)
    {
        printf("counter = %d\n", counter);
        counter++;
    }

    */
    /*
    counter = 0;
    do
    {
        counter++;
        printf("counter = %d\n", counter);
    } while (counter < 10);
    */

    return 0;
}