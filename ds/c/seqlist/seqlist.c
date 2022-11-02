#include "seqlist.h"

seqlist_t *create_empty_seqlist()
{
	// mamory allocation
	seqlist_t *l = (seqlist_t *)malloc(sizeof(seqlist_t));
	if (NULL == l) 
	{
		printf("malloc is fall!\n");
		return NULL;
	}
	// init
	memset(l, 0, sizeof(seqlist_t));
	l->n = 0;

	return l;
}

void insert_data_seqlist(seqlist_t *l, datatype_t data)
{
	l->buf[l->n++] = data;
	return;
}

void print_data_seqlist(seqlist_t *l)
{
	int i;
	for (i = 0; i < l->n; i++)
	{
		printf("%d ", l->buf[i]);
	}
	printf("\n");
	return;
}

int is_full_seqlist(seqlist_t *l)
{
	return l->n == MAX ? 1 : 0;
}

int delete_data_seqlist(seqlist_t *l, datatype_t data)
{
	int i = 0, j = 0;

	if (is_empty_seqlist(l))
		return -1;

	for (i = 0; i < l->n; i++)
	{
		if (l->buf[i] != data)
			l->buf[j++] = l->buf[i];
	}

	l->n = j;
	
	if (i == j)
		return -2;
	else
		printf("delete %d is successful!\n", data);

	return 0;	
}

int is_empty_seqlist(seqlist_t *l)
{
	return l->n == 0 ? 1 : 0;
}
