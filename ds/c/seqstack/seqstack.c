#include "seqstack.h"

seqstack_t *create_empty_seqstack()
{
    seqstack_t *s = (seqstack_t *)malloc(sizeof(seqstack_t));
    if (NULL == s)
    {
        printf("malloc is fail!\n");
        return NULL;
    }

    memset(s, 0, sizeof(seqstack_t));
    s->top = -1;

    return s;
}

void push_seqstack(seqstack_t *s, data_t data)
{
    s->buf[++s->top] = data;
    return;
}

data_t pop_seqstack(seqstack_t *s)
{
    return s->buf[s->top--];
}

int is_empty_seqstack(seqstack_t *s)
{
    return s->top == -1 ? 1 : 0;
}

int is_full_seqstack(seqstack_t *s)
{

    return s->top == MAX - 1 ? 1 : 0;
}

data_t get_top_seqstack(seqstack_t *s)
{
    return s->buf[s->top];
}