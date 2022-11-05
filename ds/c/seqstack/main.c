#include "seqstack.h"

int main(int argc, char const *argv[])
{
    int i = 0;
    seqstack_t *s;
    
    s = create_empty_seqstack();
    while(!is_full_seqstack(s))
    {
        push_seqstack(s, i++);
    }

    printf("top: %d\n", get_top_seqstack(s));

    printf("pop: %d\n", pop_seqstack(s));

    int ret;
    while(!is_empty_seqstack(s))
    {
        ret = pop_seqstack(s);
        printf("%d ",ret); 
    }
    printf("\n");

    return 0;
}
