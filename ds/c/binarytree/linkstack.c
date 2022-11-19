#include "linkstack.h"

linkstack_t *create_empty_linkstack()
{
    linkstack_t *s = (linkstack_t *)malloc(sizeof(linkstack_t));
    if (NULL == s)
    {
        printf("malloc is fail!\n");
        return NULL;
    }

    memset(s, 0, sizeof(linkstack_t));
    s->n = 0;

    return s;
}

int is_empty_linkstack(linkstack_t *s)
{
    return s->top == NULL ? 1 : 0;
}

void push_linkstack(linkstack_t *s, datatype_t data)
{
    linknode_t *tmp = (linknode_t *)malloc(sizeof(linknode_t));
    if (NULL == tmp)
    {
        printf("malloc is fail!\n");
        return;
    }

    tmp->data = data;
    tmp->next = s->top;
    s->top = tmp;
    s->n++;

    return;
}

datatype_t pop_linkstack(linkstack_t *s)
{
    linknode_t *tmp = NULL;
    datatype_t data;

    tmp = s->top;
    data = tmp->data;

    s->top = tmp->next;
    s->n--;

    free(tmp);
    tmp = NULL;

    return data;
}

datatype_t get_top_data(linkstack_t *s)
{
    return s->top->data;
}