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
#include <stdlib.h>

List* list_new()
{
	List* NewList  = (List*)malloc(sizeof(List));
	NewList->size = 0;
	NewList->head= NULL;
	NewList->tail = NULL;
	return NewList;
}

 list_delete(List *list)
{
	 if (NULL == list)
	 {
		 printf("in fuction list_delete(): empty list is not avaliable in arguments!");
		 return 1;
	 }
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
	if (NULL == list)
	{
		printf("function unshift() NULL list is not avaliable in arguments!");
		return 1;
	}
	Node* NewNode = (Node*)malloc(sizeof(Node));
	Node* Last_head;

	if (NULL == NewNode) 
	{
		printf("Error: Can't allocate memory");
		return 1;
	}

	NewNode->value = value;

	if (NULL != list->head)
	{
		Last_head = list->head;
		NewNode->prev = NULL;
		NewNode->next = list->head;
		Last_head->prev = NewNode;
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
	if (NULL == pointer)	
	{
		printf("fuction shift(): NULL poiner is not avaliable in arguments!");
		return 1;
	}
	if (NULL == list)
	{
		printf("fuction shift(): NULL list is not avaliable in arguments!");
		return 1;
	}
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
	if (NULL == list)
	{
		printf("NULL list is not avaliavle here!");
		return 1;
	}
	if (NULL == pointer)
	{
		printf("NULL pointer is not avaliable here!");
		return 1;
	}
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
	if (NULL == list)
	{
		printf("fuction push(): NULL list is not avaliable in arguments!");
		return 1;
	}
	Node* NewNode = (Node*)malloc(sizeof(Node));
	Node* PrevNewNode;

	if (NULL == NewNode)
	{
		printf("Error: Can't allocate memory");
		return 1;
	}

	NewNode->value = value;

	if (NULL != list->tail)
	{
		NewNode->next = NULL;
		NewNode->prev = list->tail;
		printf("%f", list->tail->value);
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
	if (NULL == list)
	{
		printf("functon reverse(): NULL list is not avaliable in arguments");
		return 1;
	}
	Node* current; 
	Node* tmp;
	if (NULL != list->head)
	{
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
}
