#include <stdio.h>

#define ALL     6
#define OUT     3

int people[ALL];

void init_ring(void)
{
    int i = 0;

    for (i = 0; i < ALL; i++)
        people[i] = i + 1;
    return;
}

void print_ring(void)
{
    int i = 0;

    for (i = 0; i < ALL; i++)
        printf("%d ", people[i]);
    printf("\n");

    return;
}

int main(void)
{
    int left;       /* how many people in the ring */
    int counter;
    int i;

    printf("demo josephus ring problem\n");

    init_ring();
    print_ring();

    left = ALL;     /* ALL people */
    counter = 0;
    i = 0;
    while (1) {
        if (people[i] > 0) {
            counter++;
        }

        if (counter == OUT) {   /* some is out */
            left--;
            printf("%d is out\n", people[i]);
            people[i] = 0;
            print_ring();
            counter = 0;
        }

        printf("i = %d, counter = %d, left = %d\n", i, counter, left);
        /*
        print_ring();
        */

        if (left < 1)
            break;


        i = (++i) % ALL;
        /* getchar(); */
    }

    printf("problem is finished\n");

    return 0;
}