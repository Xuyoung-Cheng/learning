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
