#pragma once

/*
 * File: bst.h
 * Brief: Binary search tree
 * Author: Redkozubova Nastia
 * Created on: 04.12.2019
 * (c) MIPT
*/

#include <stdio.h>
typedef struct edge *pedge;

struct edge
{
	pedge left;
	pedge right;
	double value;
	int key;
};

/*
 * Creates an empty tree
 * Params: none
 * Returns pointer to the tree
 */
pedge new_tree(void);

/*
* Insert a piar (key, value) into tree
* Params: tree - pointer to the root, key - integer number, value - integer number
* Return: 0 if inserting was successful, -1 if inserting was unsuccessful
*/
int add_edge(pedge root, int key, double value);

/*
* Delete tree
* Params: tree - pointer to the root
* Returns none
*/
void delete_tree(pedge tree);

/*
* Depth first search (print the elements)
* Params: tree - pointer to the root
* Returns: value of current element (or -1.0 if the tree is empty)
*/
double dfs(pedge root);


/*
* Width first search (print the elements)
* Params: tree - pointer to the root
* Returns: 0 if passing was successful, -1 if passing was unsuccessful
*/
double wfs(pedge root);