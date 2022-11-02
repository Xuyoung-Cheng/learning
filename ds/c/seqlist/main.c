#include "seqlist.h"

int main(int argc, char *argv[])
{
	seqlist_t *l = create_empty_seqlist();
	datatype_t data;
	int ret;

	printf("please in put %d numbers : ", MAX);
	while(!is_full_seqlist(l))
	{
		scanf("%d", &data);
		insert_data_seqlist(l, data);
	}

	print_data_seqlist(l);

	printf("===========================================\n");
	printf("please input you want to delete data : ");
	scanf("%d", &data);

	ret = delete_data_seqlist(l, data);
	if (ret < 0);
	{
		printf("seqlist is empty or data is not exist!\n");
		return -1;
	}

	print_data_seqlist(l);

	free(l);
	l = NULL;

	return 0;
}
