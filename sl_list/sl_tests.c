/*
 * File:  sl_tests.c
 * Brief: testing main fuctions for single lincked list
 * Created on 02.12.2019
 * Author: Kasapenko Natalya
 * (c) MIPT 2019
 */

#include <stdio.h>
#include "sl_list.h"

 /*
 * test1
 * cheking work of function slist_new()
 */
//works OK
int test1()
{
	pslist list;

	list = slist_new();

	if (NULL != list->head)
		goto errorpath;
	if (NULL != list->list_size)
		goto errorpath;

	printf("List Created!");

	return 0;

errorpath:
	return 1;
	printf("Error: mistakes in creatin the list");
}

/*
* test2
* checking work of function slist_insert() and slist_print()
*/
//works OK
int test2()
{
	pslist list;

	int result = 0;

	list = slist_new();

	slist_print(list);  //prints an empty list - OK

	result = result + slist_insert(list, 1);

	if (1 != list->list_size)
		goto errorpath;

	slist_print(list);
	printf("\n");

	result = result + slist_insert(list, 2);
	if (2 != list->list_size)
		goto errorpath;

	slist_print(list);
	printf("\n");

	result = result + slist_insert(list, 3);
	if (3 != list->list_size)
		goto errorpath;

	slist_print(list);
	printf("\n");

	return result;

errorpath:
	result = 1;
}

/*
* test3()
* checks work of function list_delete();
*/
//works OK/ 
int test3()
{
	pslist list;

	list = slist_new();

	slist_insert(list, 1);
	slist_insert(list, 2);

	slist_print(list);
	printf("\n");

	slist_delete(list);

	slist_print(list);

	return 0;
}

/*
* test4
* cheking work of function slist_remove()
*/
//got ann error/ programme crushes
int test4()
{
	pslist list;

	list = slist_new();

	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_insert(list, 4);
	slist_insert(list, 2);

	slist_print(list);
	printf("\n");

	slist_remove(list, 2);

	slist_print(list);

	return 0;
}


