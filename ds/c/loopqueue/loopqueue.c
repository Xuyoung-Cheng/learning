#include "loopqueue.h"

loopqueue_t *create_empty_loopqueue()
{
    loopqueue_t *q;

    q = (loopqueue_t *)malloc(sizeof(loopqueue_t));
    if (NULL == q)
    {
        printf("malloc is fail!\n");
        return NULL;
    }

    memset(q, 0, sizeof(loopqueue_t));
    q->front = q->rear = 0;

    return q;
}

int is_empty_loopqueue(loopqueue_t *q)
{
    return q->front == q->rear ? 1 : 0;
}

int is_full_loopqueue(loopqueue_t *q)
{
    return q->front == ((q->rear + 1) % N) ? 1 : 0;
}

void enter_loopqueue(loopqueue_t *q, data_t data)
{
    q->buf[q->rear] = data;
    q->rear = (q->rear + 1) % N;
    return;
}

data_t delete_loopqueue(loopqueue_t *q)
{
    data_t data;

    data = q->buf[q->front];
    q->front = (q->front + 1) % N;
    return data;
}
