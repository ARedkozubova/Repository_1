#pragma once
/*
 * File: dl_list.h
 * Brief: Double linked list header
 * Author: Kasapenko Natalya
 * Created on: 02.12.2019
 * (c) MIPT
*/

typedef struct List* p_list;
typedef struct Node* p_node;

typedef struct _Node
{
	int value;
	struct p_node* next;
	struct p_node* prev;
} Node;

typedef struct _List
{
	int size;
	p_node* head;
	p_node* tail;
} List;

/*
* function: list_new() creates new empty list
* arguments: none
* returning values:
*		Link to the list if list is creared
*		1 if list is not created
* creates new empty lincked list
*/
p_list list_new();

/*
* function: list_delete(List* list) deletes list and all elements in it
* arguments: List* list (pointer to the head of the list)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
void list_delete(p_node list);

/*
* function: push(List* list, int value) adds new element in the end of the list
* arguments: List* list (pointer to the head of the list)
			 int value (pushing number)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int push(p_list list, int value);

/*
* function: pop(List* list, int value) gets the last element of the list
* arguments: List* list (pointer to the head of the list)
			 int pointer (pointer where to push popped element)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int pop(p_node* list, int* pointer);

/*
* function: unshift(List* list, int value) adds new element in the beginning of the list
* arguments: List* list (pointer to the head of the list)
			 int value (new value)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int unshift(p_node* list, int value);

/*
* function: shift(List* list, int value) gets the first element of the list
* arguments: List* list (pointer to the head of the list)
			 int* pointer (address where to put the element)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int shift(p_node* list, int* pointer);
