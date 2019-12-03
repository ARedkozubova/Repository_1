/*
 * File: dl_list.c
 * Brief: Double linked list
 * Author: Kasapenko Natalya
 * Created on: 02.12.2019
 * (c) MIPT
*/

#pragma once
#include "dl_list.h"
#include <stdio.h>

List* list_new()
{
	List *NewList = (List*)malloc(sizeof(List));
	NewList->size = 0;
	NewList->head= NULL;
	NewList->tail = NULL;
	return NewList;
}

void list_delete(List *list)
{
	Node* current = list->head;
	Node* next = NULL;
	while (NULL != current) {
		next = current->next;
		free(current);
		current = next;
	}
	free(*list);
	list = NULL;
}


int unshift(List* list, int value)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NULL == NewNode) 
	{
		printf("Error: Can't allocate memory");
		exit(1);
	}

	NewNode->value = value;
	NewNode->prev = NULL;
	NewNode->next = list->head;

	if (NULL != list -> head) 
	{
		list->head = NewNode;
	}

	if (NULL == list->tail)
	{
		list->tail = NewNode;
	}

	list->size++;

	return 0;
}

int shift(List* list, int* pointer)
{

	if (NULL != list)
	{
		Node* N = (Node*)malloc(sizeof(Node));
		N = list->head;
		pointer = N->value;
		return 0;
	}
	else
	{
		printf("list doesn't exist");
		return 1;
	}
}

int pop(List* list, int* pointer)
{
	if (NULL != list)
	{
		Node* N = (Node*)malloc(sizeof(Node));
		N = list->tail;
		pointer = N->value;
		return 0;
	}
	else
	{
		printf("list doesn't exist");
		return 1;
	}
} 

int push(List* list, int value)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	Node* Element;

	if (NULL == NewNode)
	{
		printf("Error: Can't allocate memory");
		exit(1);
	}
	NewNode->value = value;
	NewNode->next = NULL;
	NewNode->prev = list->tail;

	if (NULL != list->tail)
	{
		Element = list->tail;
		Element->next = NewNode;
	}
	if (NULL == list->head)
	{
		list->head = NewNode;
	}

	return 0;
}

void reverse(List* list)
{
	Node* current; 
	Node* tmp;
	current = list->head;
		while (current != NULL)
		{
			tmp = current->next;
			current->next = current->prev;
			current->prev = tmp;
			current = current->prev;
		}
	current = list->head;
	list->head = list->tail;
	list->tail = current;
}
