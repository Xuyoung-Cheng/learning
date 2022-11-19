#include "linkqueue.h"

linkqueue_t *create_empty_linkqueue()
{
    linknode_t *head = (linknode_t *)malloc(sizeof(linknode_t));
    if (NULL == head)
    {
        printf("malloc is fail\n");
        return NULL;
    }
    memset(head, 0, sizeof(linknode_t));

    head->next = NULL;

    linkqueue_t *q = (linkqueue_t *)malloc(sizeof(linkqueue_t));
    if (NULL == q)
    {
        printf("malloc is fail\n");
        return NULL;
    }
    memset(q, 0, sizeof(linkqueue_t));

    q->front = head;
    q->rear = head;

    return q;
}

int is_empty_linkqueue(linkqueue_t *q)
{
    return q->front == q->rear ? 1 : 0;
}

void enter_linkqueue(linkqueue_t *q, datatype_t data)
{
    linknode_t *tmp = (linknode_t *)malloc(sizeof(linknode_t));
    if (NULL == tmp)
    {
        printf("malloc is fail\n");
        return;
    }

    tmp->data = data;
    tmp->next = q->rear->next;
    q->rear->next = tmp;
    
    q->rear = tmp;
    return;
}

datatype_t delete_linkqueue(linkqueue_t *q)
{
    linknode_t *tmp = NULL;
    datatype_t data;

    tmp = q->front->next;
    data = tmp->data;

    q->front->next = tmp->next;
    free(tmp);
    tmp = NULL;

    if (q->front->next == NULL)
        q->rear = q->front;

    return data;
}