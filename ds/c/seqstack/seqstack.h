#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;

#define MAX     5

typedef struct
{
    data_t buf[MAX];
    int top;
}seqstack_t;

extern seqstack_t *create_empty_seqstack();
extern void push_seqstack(seqstack_t *s, data_t data);
extern data_t pop_seqstack(seqstack_t *s);
extern int is_empty_seqstack(seqstack_t *s);
extern int is_full_seqstack(seqstack_t *s);
extern data_t get_top_seqstack(seqstack_t *s);

#endif