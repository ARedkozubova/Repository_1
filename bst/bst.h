#pragma once

/*
 * File: bst.h
 * Brief: Binary search tree
 * Author: Redkozubova Nastia
 * Created on: 04.12.2019
 * (c) MIPT
*/

typedef struct edge *pedge;

struct edge
{
	pedge left;
	pedge right;
	int value;
	int key;
};

/*
 * Creates an empty tree
 * Params: none
 * Returns pointer to the
 */
pedge new_tree(void);

/*
* Insert a piar (key, value) into tree
* Params: tree - pointer to the root, key - integer number, value - integer number
* Return: 0 if inserting was successful, -1 if inserting was unsuccessful
*/
int add_edge(pedge root, int key, int value);
