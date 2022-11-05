#include "looplist.h"

loopnode_t *create_empty_looplist()
{
	loopnode_t *head = NULL;
	head = (loopnode_t *)malloc(sizeof(loopnode_t));

	if (NULL == head)
	{
		printf("malloc is fail\n");
		return NULL;
	}
	memset(head, 0, sizeof(loopnode_t));
	head->next = head;
	return head;
}

void insert_head_looplist(loopnode_t *head, datatype_t data)
{
	loopnode_t *temp = (loopnode_t *)malloc(sizeof(loopnode_t));
	if (NULL == temp)
	{
		printf("malloc is fail\n");
		return;
	}
	
	temp->data = data;
	temp->next = head->next;
	head->next = temp;

	return;
}

void insert_tail_looplist(loopnode_t *head, datatype_t data)
{
	loopnode_t *temp = (loopnode_t *)malloc(sizeof(loopnode_t));
	if (NULL == temp)
	{
		printf("malloc is fail\n");
		return;
	}

	temp->data = data;
	loopnode_t *p = head;
	while(p->next != head)
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;

	return;
}

void print_data_looplist(loopnode_t *head)
{
	loopnode_t *p = head;
	while(p->next != head)
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
	return;
}


int is_empty_looplist(loopnode_t *head)
{
	return head->next == head ? 1 : 0;
}

