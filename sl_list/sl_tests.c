/*
 * File:  sl_tests.c
 * Brief: testing main fuctions for single lincked list
 * Created on 02.12.2019
 * Author: Kasapenko Natalya
 * (c) MIPT 2019
 */

#include <stdio.h>
#include "sl_list.h"
#include "sl_tests.h"

int test1()
{
	pslist list;

	list = slist_new();

	if (NULL != list->head)
		goto errorpath;
	if (NULL != list->list_size)
		goto errorpath;

	return 0;

errorpath:
	return 1;
}

int test2()
{
	pslist list;

	int result = 0;

	list = slist_new();

	result = result + slist_insert(list, 1);

	if (1 != list->list_size)
		goto errorpath;

	result = result + slist_insert(list, 2);
	if (2 != list->list_size)
		goto errorpath;

	result = result + slist_insert(list, 3);
	if (3 != list->list_size)
		goto errorpath;

	return result;

errorpath:
	result = 1;
}

int test3()
{
	pslist list;

	list = slist_new();

	slist_insert(list, 2);
	slist_insert(list, 3);
	slist_insert(list, 4);

	if (list->list_size == 3)
	{
		return 0;
	}
	else return 1;
}

int test4()
{
	pslist list;

	list = slist_new();

	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_insert(list, 3);
	slist_insert(list, 4);
	slist_insert(list, 2);

	slist_remove(list, 2);
	slist_remove(list, 1);

	int summ1;
	summ1 = (slist_find(list, 1) + slist_find(list, 2));
	if (summ1 == 0) return 0;
	else return 1;
} 


void test5()
{
	pslist list;

	list = slist_new();

	slist_insert(list, 1);
	slist_insert(list, 2);

	slist_print(list);
	printf("\n");

	slist_delete(list);

	slist_print(list);
}


void test6()
{
	pslist list;
	list = slist_new();
	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_insert(list, 3);
	slist_print(list);
}

int slist_find(pslist list, int value)
{
	pslist_entry current;
	current = list->head;
	int found = 0;
	while (NULL != current->next)
	{
		if (current->value == value)
		{
			found = 1;
		}
		current = current->next;
	}
	if (found == 1) return 1;
	if (found == 0) return 0;
}

void run_all_tests()
{
	int A[4];
	A[0] = test1();
	A[1] = test2();
	A[2] = test3();
	A[3] = test4();
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (A[i] == 0) printf("test%d: COMPLETED!\n", i + 1);
		else printf("test%d: FAILED!\n", i + 1);
	}
}



