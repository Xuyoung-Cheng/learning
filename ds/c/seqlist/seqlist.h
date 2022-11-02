#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	10

typedef int datatype_t;

typedef struct
{
	datatype_t buf[MAX];  // an array to store info.
	int n;		      // the actual number of elements.
}seqlist_t;

extern seqlist_t *create_empty_seqlist();
extern void insert_data_seqlist(seqlist_t *l, datatype_t data);
extern void print_data_seqlist(seqlist_t *l);
extern int is_full_seqlist(seqlist_t *l);
extern int delete_data_seqlist(seqlist_t *l, datatype_t data);
extern int is_empty_seqlist(seqlist_t *l);

#endif
