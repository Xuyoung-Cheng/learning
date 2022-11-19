#include "binarytree.h"

bitree_t *create_binary_tree(int n)
{
    bitree_t *root = NULL;
    root = (bitree_t *)malloc(sizeof(bitree_t));
    memset(root, 0, sizeof(bitree_t));

    root->n = n;
    root->lchild = root->rchild = NULL;

    printf("please input %d data : ", n);
    scanf("%c", &(root->data));

    while (getchar() != '\n');
    
    if (2 * n <= N)
    {
        root->lchild = create_binary_tree(2 * n);
    }

    if (2 * n + 1 <= N)
    {
        root->rchild = create_binary_tree(2 * n + 1);
    }

    return root;
}

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