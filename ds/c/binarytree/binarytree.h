#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6

typedef char data_t;

typedef struct bitree
{
    int n;
    data_t data;
    struct bitree *lchild;
    struct bitree *rchild;
}bitree_t;

extern bitree_t *create_binary_tree(int n);
extern void pre_order(bitree_t *root);
extern void in_order(bitree_t *root);
extern void post_order(bitree_t *root);

#endif