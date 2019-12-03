/*
 * File: dl_list
 * Brief: Double linked list header
 * Author: Anastasia Redkozubova
 * Created on: 03.12.2019
 * (c) MIPT
*/

#include <stdio.h>
#include "dl_list.h"


int find_element(List *list, int value)
{
	int flag = 0;
	Node *current = list->head;
	while (NULL != current)
	{
		if (current->value == value)
			flag = 1;
		current = current->next;
	}
	return flag;
}


int test_new()
{
	List *list;
	list = list_new();
	if (NULL == list)
	{
		printf("ERROR in test_new: creation of list is incorrect!\n");
		return -1;
	}
	if (NULL != list->head)
	{
		printf("%ERROR in test_new: first element is not NULL!\n");
		return -2;
	}
	if (NULL != list->tail)
	{
		printf("%ERROR in test_new: last element is not NUL!L\n");
		return -3;
	}
	else
	{
		printf("PASS: test_new\n");
		return 0;
	}
	list_delete(list);
}

int test_push()
{
	List *list;
	list = list_new();
	int i = 0, count = 0, flag = 1;
	for (i = 0; i < 20; i++)
	{
		push(list, i);
	}
	for (i = 0; i < 20; i++)
	{
		if (find_element(list, i))
			count++;
		else
			flag = 0;
	}
	if(!flag)
	{
		printf("ERROR in test_push: element was not pushed!\n");
		return -1;
	}
	if (count != list->size)
	{
		printf("ERROR in test_push: amount of element is not equal size of list!\n");
		return -2;
	}
	else
	{
		printf("PASS: test_push\n");
		return 0;
	}
}
