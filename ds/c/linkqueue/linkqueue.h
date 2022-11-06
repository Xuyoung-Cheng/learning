#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int data_t;

typedef struct node
{
    data_t data;
    struct node *next;
}linknode_t;


typedef struct
{
    linknode_t *front;
    linknode_t *rear;
}linkqueue_t;

extern linkqueue_t *create_empty_linkqueue();
extern int is_empty_linkqueue(linkqueue_t *q);
extern void enter_linkqueue(linkqueue_t *q, data_t data);
extern data_t delete_linkqueue(linkqueue_t *q);

#endif