#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 123

typedef int data_t;

typedef struct node
{
    data_t data;
    struct node *next;
}linknode_t;

//链式栈栈头类型
typedef struct 
{
    linknode_t *top;
    int n;
}linkstack_t;

//链式队列的队列头的类型 
typedef struct 
{
    linknode_t *front;
    linknode_t *rear;
}linkqueue_t;

//链式栈的操作
extern linkstack_t *create_empty_linkstack();
extern int is_empty_linkstack(linkstack_t *s);
extern int push_linkstack(linkstack_t *s,data_t data);
extern data_t pop_linkstack(linkstack_t *s);
extern data_t get_top_data(linkstack_t *s);

//链式队列的操作
extern linkqueue_t *create_empty_linkqueue();
extern int is_empty_linkqueue(linkqueue_t *q);
extern int enter_linkqueue(linkqueue_t *q,data_t data);
extern data_t delete_linkqueue(linkqueue_t *q);

#endif
