#include "linkqueue.h"

int main(int argc, char const *argv[])
{
    linkqueue_t *q = NULL;
    int i = 0;

    q = create_empty_linkqueue();

    for (i = 0; i < 10; i++)
    {
        enter_linkqueue(q, i);
    }

    while(!is_empty_linkqueue(q))
    {
        printf("%d ", delete_linkqueue(q));
    }
    printf("\n");

    return 0;
}
