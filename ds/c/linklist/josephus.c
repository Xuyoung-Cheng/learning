#include "looplist.h"

void josephus(loopnode_t *head, int k, int m)
{
	loopnode_t *p = NULL;
	loopnode_t *q = NULL;
	int i = 0;

	p = head;
	for (i = 1; i < k; i++)     // find previous position
		p = p->next;

	i = 1;
	while (!is_empty_looplist(head))
	{
		printf("list: ");
		print_data_looplist(head);
		if (i == m)            // delete node
		{
			if (p->next == head)
			{
				q = p->next->next;
				p->next->next = q->next;
			}
			else
			{
				q = p->next;
				p->next = q->next;
			}
			printf("---------------------------------%d\n", q->data);

			free(q);
			q = NULL;
			i = 1;
		}
		else 
		{
			i++;
			if (p->next == head)
				p = p->next->next;
			else
				p = p->next;
		}
	}

	return;
}

int main(int argc, char *argv[])
{
	int n = 0, k = 0, m = 0;
	loopnode_t *head = create_empty_looplist();
	int i = 0;
	
	printf("please input n people, start at k, counter m : ");
	scanf("%d%d%d", &n, &k, &m);
	for (i = 1; i <= n; i++)
		insert_tail_looplist(head, i);	
	josephus(head, k, m);

	return 0;
}
