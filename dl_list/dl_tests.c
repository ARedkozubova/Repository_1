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

void fill_list(List *list, int number)
{
	int i = 0;
	for (i = 0; i < number; i++)
	{
		push(list, i);
	}
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
	int i = 0, count = 0, flag = 1;
	list = list_new;
	fill_list(list, 20);
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
	printf("PASS: test_push\n");
	return 0;
}

int test_delete()
{
	List *list1 = list_new, *list2 = list_new;
	fill_list(list1, 20);
	list_delete(list1);
	list_delete(list2);
	return 0;
}

int test_pop()
{
	List *list = list_new;
	int *pointer = NULL, size = 0;
	pop(list, pointer);
	if (pointer != NULL)
	{
		printf("ERROR in test_pop: smth wrong with deleting from empty list!\n");
		return -1;
	}
	fill_list(list, 20);
	size = 20;
	Node *tail = list->tail;
	pop(list, pointer);
	if (NULL == pointer)
	{
		printf("ERROR in test_pop: pointer is NULL!\n");
		return -2;
	}
	if (list->size != size - 1)
	{
		printf("ERROR in test_pop: wrong size of list!\n");
		return -3;
	}
	if (find_element(list, tail) == 0)
	{
		printf("ERROR in test_pop: element was not deleted!\n");
		return -4;
	}
	if (pointer != tail)
	{
		printf("ERROR in test_pop: pointer is wrong!\n");
		return -5;
	}
	printf("PASS: test_pop\n");
	return 0;
}

int test_unshift()
{
	List *list = list_new;
	unshift(list, 15);
	if (list->head->value != 15)
	{
		printf("ERROR in test_unshift: element was not added to the list!\n");
		return -1;
	}
	if (list->size != 1)
	{
		printf("ERROR in test_unshift: wrong size of the list!\n");
		return -2;
	}
	fill_list(list, 20);
	unshift(list, 30);
	int size = 20;
	if (list->head->value != 30)
	{
		printf("ERROR in test_unshift: element was not added to the list!\n");
		return -1;
	}
	if (list->size != size + 1)
	{
		printf("ERROR in test_unshift: wrong size of the list!\n");
		return -2;
	}
	printf("PASS: test_unshift\n");
	return 0;
}

int test_shift()
{
	List *list = list_new;
	int *pointer = NULL;
	if (!shift(list, pointer))
	{
		printf("ERROR in test_shift: fail to process deleting from empty list!\n");
		return -1;
	}
	fill_list(list, 20);
	int size = 20;
	int *check_pointer = list->head;
	shift(list, pointer);
	if (pointer != check_pointer)
	{
		printf("ERROR in test_shift: pointer does not contain the right value!\n");
		return -2;
	}
	if (list->size != size - 1)
	{
		printf("ERROR in test_shift: wrong size of the list!\n");
		return -3;
	}
	printf("PASS: test_shift\n");
	return 0;
}
