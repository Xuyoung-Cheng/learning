#include "looplist.h"

int main(int argc, char *argv[])
{
	loopnode_t *head = NULL;
	datatype_t data;
	int n = 0, i = 0;

	head = create_empty_looplist();
	printf("please input you want insert data number : ");
	scanf("%d", &n);
	
	printf("please input %d data : ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &data);
		insert_head_looplist(head, data);
	}
	print_data_looplist(head);

	return 0;
}
