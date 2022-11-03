#include "linklist.h"


int main(int argc, char *argv[])
{
	linknode_t *head = NULL;
	datatype_t data;
	int n = 0, i = 0;

	head = create_empty_linklist();
	printf("please input you want insert data number : ");
	scanf("%d", &n);
	
	printf("please input %d data : ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &data);
		insert_order_linklist(head, data);
	}
	print_data_linklist(head);

	printf("please input you want delete data : ");
	scanf("%d", &data);

	int ret = delete_data_linklist(head, data);
	if (ret < 0)
	{
		printf("data is not exist or is empty\n");
		return -1;
	}
	print_data_linklist(head);

	reverse_data_linklist(head);
	print_data_linklist(head);

	clean_up_linklist(head);
	return 0;
}
