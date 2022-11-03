#include "linklist.h"

linknode_t *create_empty_linklist()
{
	linknode_t *head = NULL;
	head = (linknode_t *)malloc(sizeof(linknode_t));

	if (NULL == head)
	{
		printf("malloc is fail\n");
		return NULL;
	}
	memset(head, 0, sizeof(linknode_t));
	return head;
}

void insert_head_linklist(linknode_t *head, datatype_t data)
{
	linknode_t *temp = (linknode_t *)malloc(sizeof(linknode_t));
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

void insert_tail_linklist(linknode_t *head, datatype_t data)
{
	linknode_t *p;
	linknode_t *temp = (linknode_t *)malloc(sizeof(linknode_t));
	if (NULL == temp)
	{
		printf("malloc is fail\n");
		return;
	}
	
	temp->data = data;
	
	p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}

	temp->next = p->next;
	p->next = temp;

	return;
}

void insert_order_linklist(linknode_t *head, datatype_t data)
{
	linknode_t *temp = (linknode_t *)malloc(sizeof(linknode_t));
	if (NULL == temp)
	{
		printf("malloc is fail\n");
		return;
	}
	
	temp->data = data;
	
	linknode_t *p = head;
	while(p->next != NULL && data > p->next->data)
	{
		p = p-> next;
	}
	temp->next = p->next;
	p->next = temp;

	return;
}

void print_data_linklist(linknode_t *head)
{
	linknode_t *p = head;
	while(NULL != p->next)
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
	return;
}


int is_empty_linklist(linknode_t *head)
{
	return head->next == NULL ? 1 : 0;
}

int delete_data_linklist(linknode_t *head, datatype_t data)
{
	linknode_t *p = NULL;
	linknode_t *q = NULL;
	int flag = 0;

	if (is_empty_linklist(head))
	{
		return -1;
	}

	p = head;
	while(p->next != NULL)
	{
		if (p->next->data == data)
		{
			q = p->next;
			p->next = q->next;
			free(q);

			q = NULL;
			flag = 1;
		} else {
			p = p->next;
		}
	}

	if (flag == 0)
		return -2;
	else
	{
		printf("delete %d is successful\n", data);
		return 0;
	}
}

void reverse_data_linklist(linknode_t *head)
{
	linknode_t *p = NULL;
	linknode_t *q = NULL;

	p = head->next->next;
	head->next->next = NULL;

	while(p != NULL)
	{
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}

	return ;
}

void clean_up_linklist(linknode_t *head)
{
	linknode_t *p = NULL;
	linknode_t *q = NULL;
	
	p = head;
	while (p != NULL)
	{
		q = p->next;
		print_data_linklist(p);
		free(p);
		p = q;
	}	
	return;
}
