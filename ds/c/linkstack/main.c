#include "linkstack.h"

int main(int argc, char const *argv[])
{
    linkstack_t *s;
    data_t array[] = {'a', 'n', 'i', 'h', 'c'};
    int i = 0;

    s = create_empty_linkstack();
    for (i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    {
        push_linkstack(s, array[i]);
    }

    printf("Top data = %c\n", get_top_data(s));

    while(!is_empty_linkstack(s))
    {
        printf("%c", pop_linkstack(s));
    }
    printf("\n");

    return 0;
}
