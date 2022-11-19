#include "binarytree.h"
#include "linkstack.h"


void pre_order(bitree_t *root)
{
    linkstack_t *s = NULL;
    bitree_t *temp = NULL;

    if (NULL == root)
        return;

    s = create_empty_linkstack();
    temp = root;
    while (temp != NULL || !is_empty_linkstack(s)) {
        while (temp != NULL) {
            printf("(%d, %c) ", temp->n, temp->data);
            push_linkstack(s, temp);
            temp = temp->lchild;
        }

        if (!is_empty_linkstack(s)) {
            temp = pop_linkstack(s);
            temp = temp->rchild;
        }
    }

    free(s);
    return;
}

void in_order(bitree_t *root)
{
    linkstack_t *s = NULL;
    bitree_t *temp = NULL;

    if (NULL == root)
        return;

    s = create_empty_linkstack();
    temp = root;
    while (temp != NULL || !is_empty_linkstack(s)) {
        if (temp != NULL) {
            push_linkstack(s, temp);
            temp = temp->lchild;
        } else {
            temp = pop_linkstack(s);
            printf("(%d, %c) ", temp->n, temp->data);
            temp = temp->rchild;
        }
    }

    free(s);
    return;
}

void post_order(bitree_t *root)
{
    linkstack_t *s = NULL;
    bitree_t *cur = NULL;
    bitree_t *pre = NULL;

    if (NULL == root)
        return;

    s = create_empty_linkstack();
    push_linkstack(s, root);
    while (!is_empty_linkstack(s)) {
        cur = get_top_data(s);

        if ((cur->lchild == NULL && cur->rchild == NULL) || \
            (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            printf("(%d: %c) ", cur->n, cur->data);
            pop_linkstack(s);
            pre = cur;
        } else {
            if (cur->rchild != NULL)
                push_linkstack(s, cur->rchild);
            if (cur->lchild != NULL)
                push_linkstack(s, cur->lchild);
        }
    }

    free(s);
    return;
}