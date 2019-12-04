/*
 * This file is bst.c
 * Binary search tree implementation
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

 /*
  * Creates an empty tree
  */
pedge new_tree(void)
{
	pedge root = malloc(sizeof(struct edge));
	if (NULL == root)
	{
		printf("ERROR: failed allocation of memory for new tree!\n");
		return NULL;
	}
	root->left = NULL;
	root->right = NULL;
	root->key = NULL;
	root->value = NULL;
	return root;
}