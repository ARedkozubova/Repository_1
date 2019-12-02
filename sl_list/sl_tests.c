/*
 * File:  sl_tests.c
 * Brief: testing main fuctions for single lincked list
 * Created on 02.12.2019
 * Author: Kasapenko Natalya
 * (c) MIPT 2019
 */

#include <stdio.h>
#include "sl_list.h"
#include < assert.h > 


/*
* test1
* cheking work of function slist_new()
*/
int test1()
{
	pslist list;

	list = slist_new();

	if (NULL != list)
	{
		printf("List created! %p\n", list);
	}

	else
	{
		printf("ERROR: List was not created!");
	}
}

/*
* test3
* checking work of function slist_insert()
*/
int test2()
{
	pslist list;

	list = slist_new();

	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_insert(list, 3);

	slist_print(list);

	return 0;
} 
