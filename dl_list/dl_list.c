/*
 * File: dl_list
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
	List* NewList = (List*)malloc(sizeof(List));
	NewList->size = 0;
	NewList->head= NULL;
	NewList->tail = NULL;
	return NewList;
}

 list_delete(List *list)
{
	Node* current = list->head;
	Node* next = NULL;
	while (NULL != current) {
		next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	free(list);
	return 0;
}

int unshift(List* list, int value)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	Node* NextNewNode = (Node*)malloc(sizeof(Node));

	if (NULL == NewNode) 
	{
		printf("Error: Can't allocate memory");
		exit(1);
	}

	NewNode->value = value;

	if (NULL != list ->head)
	{
		NewNode->prev = NULL;
		NewNode->next = list->head;
		NextNewNode = list->head;
		NextNewNode->prev = NewNode;
		list->head = NewNode;
		list->size++;
	}

	else
	{
		NewNode->prev = NULL;
		NewNode->next = NULL;
		list->head = NewNode;
		list->tail = NewNode;
		list->size = 1;
	}
	return 0;
}

int shift(List* list, int* pointer)
{
	if (NULL != list->head)
	{
		Node* FirstNode = list->head;
		*pointer = (int)(FirstNode->value);
		return 0;
	}
	else
	{
		printf("First element doesn't exist");
		return 1;
	}
}

int pop(List* list, int* pointer)
{
	if (NULL != list->tail)
	{
		Node* LastNode = list->tail;
		*pointer = (int)(LastNode->value);
		return 0;
	}
	else
	{
		printf("Last element doesn't exist");
		return 1;
	}
} 

int push(List* list, int value)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	Node* PrevNewNode = (Node*)malloc(sizeof(Node));

	if (NULL == NewNode)
	{
		printf("Error: Can't allocate memory");
		exit(1);
	}

	NewNode->value = value;

	if (NULL != list->tail)
	{
		NewNode->next = NULL;
		NewNode->prev = list->tail;
		PrevNewNode = list->tail;
		PrevNewNode->next = NewNode;
		list->tail = NewNode;
		list->size++;		
	}
	else
	{
		list->head = NewNode;
		list->tail = NewNode;
		list->size = 1;
		NewNode->next = NULL;
		NewNode->prev = NULL;
	}

	return 0;
}

void print(List* list)
{
	Node* current = NULL;

	if (NULL != list->head)
	{
		current = list->head;
	}
	else
	{
		printf("List is empty");
	}

	while (NULL != current)
	{
		if (current->value == NULL)
		{
			printf("Error: value = NULL");
		}
		else
		{
			printf("%d ", current->value);
		}
		current = current->next;
	}
}

void reverseprint(List* list)
{
	Node* current = NULL;

	if (NULL != list->tail)
	{
		current = list->tail;
	}
	else
	{
		printf("List is empty");
	}

	while (NULL != current)
	{
		printf("%d ", current->value);
		current = current->prev;
	}
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
