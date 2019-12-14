/*
File: tests.c
tests for Binary Tree
Created on: 15.12.19
Author: Kasapenko Natalya
*/

#include "bst.h"
#include "tests.h"

int test1()
{
	pedge pointer;
	pointer = new_tree();
	int counter = 0;
		if (NULL == pointer)
		{
			printf("(test1)Error: didn't got a pointer");
			counter++;
			return 1;
		}
		if (NULL != pointer->left)
		{
			printf("(test1)Error: left branch is not empty");
			counter++;
			return 1;
		}
		if (NULL != pointer->right)
		{
			printf("(test1)Error: right branch is not empty");
			counter++;
			return 1;
		}
		if (NULL != pointer->key)
		{
			printf("(test1)Error: key is not NULL");
			counter++;
			return 1;
		}
		if (0 != pointer->value)
		{
			printf("(test1)Error: value is not 0");
			counter++;
			return 1;
		}
		if (counter == 0)
			return 0;
}

/*
checks what happens if pedge = NULL - infinite debug
*/
int test3()
{
	pedge Node;
	Node = new_tree();
	//add_edge(NULL, 20, 2.2);
	return 1;
}

/*
checks work of function delete_tree()
*/
int test4()
{
	pedge Node;
	Node = new_tree();
	add_edge(Node, 1, 3);
	add_edge(Node, 2, 4);
	add_edge(Node, 3, 2);

	printf("%f", Node->left->value);
	
	pedge current;

	current = Node->left;

	delete_tree(Node);

	if (current->value == 2)
	{
		printf("test4(): error: tree was not deleted");
		return 1;
	} 
	return 0;
}

/*
checks work of function delete_tree() if part of argument is not the root of the tree
*/
int test5()
{
	pedge Node;
	Node = new_tree();

	add_edge(Node, 1, 10);
	add_edge(Node, 2, 15);
	add_edge(Node, 3, 5);
	add_edge(Node, 4, 12);
	add_edge(Node, 5, 20);

	delete_tree(Node->right);

	if (Node->left->value != 5)
	{
		printf("test5(): Error: unwanted edges were deleted!");
		return 1;
	}

	if (Node->right != NULL)
	{
		printf("test5(): Error: pointer to deleted edge was not deleted!");
		return 1;
	}
	return 0;
}

/*
checks work of function add_edge()
*/
int test6()
{
	pedge Node;
	Node = new_tree();

	add_edge(Node, 1, 10);
	add_edge(Node, 2, 15);
	add_edge(Node, 3, 5);
	add_edge(Node, 4, 12);
	add_edge(Node, 5, 20);

	printf("%f", Node->value);
	printf("%f", Node->left->value);
	printf("%f", Node->right->value);
	printf("%f", Node->right->left->value);
	printf("%f", Node->right->right->value);

	if (Node->value == 10
		&&
		Node->left->value == 5
		&&
		Node->right->value == 15
		&&
		Node->right->left->value == 12
		&&
		Node->right->right->value == 20)
	{
		return 0;
	}
	else
	{
		printf("test5(): error in values in the tree");
		return 1;
	}
}

/*
checks work of function add_edge()
*/
int test7()
{
	pedge Node;
	Node = new_tree();

	add_edge(Node, 1, 10);
	add_edge(Node, 2, 15);
	add_edge(Node, 3, 16);

	if (Node->value == 10
		&&
		Node->right->value == 15
		&&
		Node->right->value == 16
		)
	{
		return 0;
	}
	else
	{
		printf("test7(): error: function add_edge() works wrongly");
		return 1;
	}
} 

/*
checks work of function wfs()
ERROR:
printed values: 20, 17, 40, 15, 30, 41
right values that must ne printed: 20, 17, 40, 12, 15, 30, 41. (12 missed)
*/
int test8()
{
	pedge Node;
	Node = new_tree();

	add_edge(Node, 1, 20);
	add_edge(Node, 2, 17);
	add_edge(Node, 3, 40);
	add_edge(Node, 3, 12);
	add_edge(Node, 3, 15);
	add_edge(Node, 3, 30);
	add_edge(Node, 3, 41);

	wfs(Node);

	return 1;
}


/*
checks work of function dfs()
ERROR: 
printed values: 15 17 20 30 40 41
right values that must be printed: 12 15 17 20 30 40 41 (12  missed)
*/
int test9()
{
	pedge Node;
	Node = new_tree();

	add_edge(Node, 1, 20);
	add_edge(Node, 2, 17);
	add_edge(Node, 3, 40);
	add_edge(Node, 3, 12);
	add_edge(Node, 3, 15);
	add_edge(Node, 3, 30);
	add_edge(Node, 3, 41);

	dfs(Node);

	return 1;
}
