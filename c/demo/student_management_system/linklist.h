#ifndef __linknode_t_H__
#define __linknode_t_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[20];
    char sex[20];
    int age;
    double score;
};

typedef struct Student datatype_t;

typedef struct node {
    datatype_t data;
    struct node *next;
} linknode_t;


extern linknode_t *create_empty_linklist();
extern void insert_head_linklist(linknode_t *head, datatype_t data);
extern void insert_tail_linklist(linknode_t *head, datatype_t data);
extern void insert_order_linklist(linknode_t *head, datatype_t data);
extern int is_empty_linklist(linknode_t *head);
extern int delete_data_linklist(linknode_t *head, int id);
extern void clean_up_linklist(linknode_t *head);

#endif