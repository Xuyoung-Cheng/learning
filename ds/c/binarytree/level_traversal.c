#include "binarytree.h"
#include "linkqueue.h"

void level_order(bitree_t *root)
{
    linkqueue_t *q = NULL;
    bitree_t *temp = NULL;

    if (NULL == root)
        return;

    q = create_empty_linkqueue();
    enter_linkqueue(q, root);
    while (!is_empty_linkqueue(q)) {
        temp = delete_linkqueue(q);
        printf("(%d, %c) ", temp->n, temp->data);
        if (temp->lchild != NULL)
            enter_linkqueue(q, temp->lchild);
        if (temp->rchild != NULL)
            enter_linkqueue(q, temp->rchild);
    }

    free(q);
    return;
}