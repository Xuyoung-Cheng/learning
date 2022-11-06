#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N   5

typedef int data_t;

typedef struct
{
    data_t buf[N];
    int front;
    int rear;
}loopqueue_t;

extern loopqueue_t *create_empty_loopqueue();
extern int is_empty_loopqueue(loopqueue_t *q);
extern int is_full_loopqueue(loopqueue_t *q);
extern void enter_loopqueue(loopqueue_t *q, data_t data);
extern data_t delete_loopqueue(loopqueue_t *q);

#endif