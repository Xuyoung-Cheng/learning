#include "binarytree.h"

void pre_order(bitree_t *root)
{
	if(NULL == root)
		return ;

	printf("(%d : %c) ",root->n,root->data);
	pre_order(root->lchild);
	pre_order(root->rchild);
}

void in_order(bitree_t *root)
{
	if(NULL == root)
		return ;

	in_order(root->lchild);
	printf("(%d : %c) ",root->n,root->data);
	in_order(root->rchild);
}

void post_order(bitree_t *root)
{
	if(NULL == root)
		return ;

	post_order(root->lchild);
	post_order(root->rchild);
	printf("(%d : %c) ",root->n,root->data);
}