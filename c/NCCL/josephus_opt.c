#include <stdio.h>

#define ALL     100
#define OUT     3

/* int people[ALL]; */
int next[ALL];      /* record the next people's index */

void init_ring(void)
{
    int i = 0;

    /*
    for (i = 0; i < ALL; i++) {
        people[i] = i + 1;
    }
    */

    for (i = 0; i < ALL; i++) {
        next[i] = (i + 1) % ALL;
    }

    return;
}

void print_ring(void)
{
    int i = 0;
    
    /*
    for (i = 0; i < ALL; i++)
        printf("%d ", people[i]);
    printf("    (p)\n");
    */

    for (i = 0; i < ALL; i++)
        printf("%d ", next[i]);
    printf("    (n)\n");

    return;
}

int main(void)
{
    int left;       /* how many people in the ring */
    int counter;
    int i;
    int prev;

    printf("demo josephus ring problem\n");

    init_ring();
    print_ring();

    left = ALL;     /* ALL people */
    counter = 0;
    i = 0;
    prev = ALL - 1;/* 0's prev = 5 */
    while (left > 0) {
        /* if (people[i] > 0) */
            counter++;

        if (counter == OUT) {   /* some is out */
            left--;
            printf("%d is out\n", i + 1);
            /* people[i] = 0; */
            /* set the next[] */
            next[prev] = next[i];
            /* print_ring(); */
            counter = 0;
        }

        /*
        printf("i = %d, counter = %d, left = %d\n", i, counter, left);
        print_ring();
        */

        prev = i;
        i = next[i];
        /* getchar(); */
    }

    printf("problem is finished\n");

    return 0;
}