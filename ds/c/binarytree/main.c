#include "binarytree.h"

int main(int argc, char const *argv[])
{
    bitree_t *root = create_binary_tree(1);
    printf("create is successful\n");

    printf("pre_order : ");
	pre_order(root);
	printf("\n");

	printf("in_order : ");
	in_order(root);
	printf("\n");

	printf("post_order : ");
	post_order(root);
	printf("\n");
	
	printf("level_order : ");
	level_order(root);
	printf("\n");

    return 0;
}
