#ifndef __LOOPLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype_t;

typedef struct node
{
	datatype_t data;
	struct node *next;
}loopnode_t;

extern loopnode_t *create_empty_looplist();
extern void insert_head_looplist(loopnode_t *head, datatype_t data);
extern void print_data_looplist(loopnode_t *head);
extern int is_empty_looplist(loopnode_t *head);
#endif
