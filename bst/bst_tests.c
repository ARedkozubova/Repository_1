/*
 * File: bst_tests.c
 * Brief: Tests for binary search tree
 * Author: Kasapenko Natalya
 * Created on: 05.12.2019
 * (c) MIPT
*/

#include "bst.h"

/*
* test1()
* checks work of function new_tree()
* returns 0 if everything is OK, returns 1 if error found
*/
int test1()
{
	pedge pointer;
	pointer = new_tree();
		if (NULL == pointer)
		{
			printf("(test1)Error: didn't got a pointer");
				return 1;
		}
		if (NULL != pointer->left)
		{
			printf("(test1)Error: left branch is not empty");
			return 1;
		}
		if (NULL != pointer->right)
		{
			printf("(test1)Error: right branch is not empty");
			return 1;
		}
		if (NULL != pointer->key)
		{
			printf("(test1)Error: key is not NULL");
			return 1;
		}
		if (0 != pointer->value)
		{
			printf("(test1)Errir: value is not 0");
		}
		else
			return 0;
}
