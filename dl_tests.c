/*
 * File: dl_list
 * Brief: Double linked list header
 * Author: Anastasia Redkozubova
 * Created on: 18.11.2019
 * (c) MIPT
*/

#include "pch.h"
#include <stdio.h>
#include "dl_list.h"

int test1()
{
	LIST *list = list_new();
	if (NULL == list)
	{
		printf("test1: list is not empty!\n");
		return -1;
	}
	if (NULL == list->first)
	{
		printf("test2: first element is not empry!\n");
		return -2;
	}


	list_delete(list);
	return 0;
}

int test2()
{
	return 0;
}

int run_all_tests()
{
	(test1 == 0) ? printf("PASS\n") : printf("FAULT\n");
	(test2 == 0) ? printf("PASS\n") : printf("FAULT\n");
	return 0;
}