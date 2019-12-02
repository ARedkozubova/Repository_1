#include <stdio.h>
#include "sl_list.h"


/*
test 1
checking if the list is created
checking if elements are inserted in the list
*/
int test1()
{
	pslist list;

	list = slist_new();
	printf("List created! %p\n", list);
	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_insert(list, 3);
	slist_print(list);

//	slist_delete(list);
	return 0;
}


int test2 ()
{
	pslist list;

	list = slist_new();

	slist_delete(list);

	printf("List deleted! %p\n", list);

	return 0;
}
