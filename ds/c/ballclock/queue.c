#include "head.h"

linkqueue_t *create_empty_linkqueue()
{
    linknode_t *head = NULL;
    linkqueue_t *q = NULL;

    head = (linknode_t *)malloc(sizeof(linknode_t));
    head->next = NULL;

    q = (linkqueue_t *)malloc(sizeof(linkqueue_t));
    q->front = q->rear = head;

    return q;
}

int is_empty_linkqueue(linkqueue_t *q)
{
    return q->front == q->rear;
}

int enter_linkqueue(linkqueue_t *q,data_t data)
{
    linknode_t *temp = NULL;

    temp = (linknode_t *)malloc(sizeof(linknode_t));
    temp->data = data;

    /*temp->next = q->rear->next;*/
    temp->next = NULL;
    q->rear->next = temp;

    q->rear = temp;

    return 0;
}

data_t delete_linkqueue(linkqueue_t *q)
{
    linknode_t *temp = NULL;

    temp = q->front;

    q->front = temp->next;

    free(temp);
    temp = NULL;

    return q->front->data;
}
