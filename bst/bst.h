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
