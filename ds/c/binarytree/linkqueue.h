#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binarytree.h"

typedef bitree_t *datatype_t;

typedef struct node
{
    datatype_t data;
    struct node *next;
}linknode_t;


typedef struct
{
    linknode_t *front;
    linknode_t *rear;
}linkqueue_t;

extern linkqueue_t *create_empty_linkqueue();
extern int is_empty_linkqueue(linkqueue_t *q);
extern void enter_linkqueue(linkqueue_t *q, datatype_t data);
extern datatype_t delete_linkqueue(linkqueue_t *q);

#endif