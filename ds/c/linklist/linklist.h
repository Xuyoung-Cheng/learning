#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype_t;

typedef struct node
{
	datatype_t data;
	struct node *next;
}linknode_t;

extern linknode_t *create_empty_linklist();
extern void insert_head_linklist(linknode_t *head, datatype_t data);
extern void print_data_linklist(linknode_t *head);
extern void insert_tail_linklist(linknode_t *head, datatype_t data);
extern void insert_order_linklist(linknode_t *head, datatype_t data);
extern int is_empty_linklist(linknode_t *head);
extern int delete_data_linklist(linknode_t *head, datatype_t data);
extern void reverse_data_linklist(linknode_t *head);
extern void clean_up_linklist(linknode_t *head);
#endif
