#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	struct list_item root;
	root.value = -1;
	root.next = NULL;

	/* Write your test cases here */
	printf("This is start of test case \n");
	//append(&root, 12);
	//append(&root, 10);
	//append(&root, 1);
	//print(&root);
	//clear(&root);

	prepend(&root, 11);
	prepend(&root, 9);
	append(&root, 33);
	input_sorted(&root,2);
	input_sorted(&root,50);
	input_sorted(&root,50);
	input_sorted(&root,1);
	input_sorted(&root,100);
	print(&root);
	clear(&root);
	return 0;
}
