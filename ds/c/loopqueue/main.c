#include "loopqueue.h"

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;

    loopqueue_t *q = create_empty_loopqueue();

    while (!is_full_loopqueue(q))
    {
        enter_loopqueue(q, i++);
    }

    while (!is_empty_loopqueue(q))
    {
        printf("%d ", delete_loopqueue(q));
    }
    printf("\n");

    return 0;
}
