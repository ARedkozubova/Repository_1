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
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct _List
{
	int size;
	Node* head;
	Node* tail;
} List;

/*
* function: list_new() creates new empty list
* arguments: none
* returning values:
*		Link to the list if list is creared
*		1 if list is not created
* creates new empty lincked list
*/
List* list_new();
/*
* function: list_delete(List* list) deletes list and all elements in it
* arguments: List* list (pointer to the head of the list)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
void list_delete(List* list);

/*
* function: push(List* list, int value) adds new element in the end of the list
* arguments: List* list (pointer to the head of the list)
			 int value (pushing number)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int push(List* list, int value);

/*
* function: pop(List* list, int value) gets the last element of the list
* arguments: List* list (pointer to the head of the list)
			 int* pointer (pointer where to push popped element)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int pop(List* list, int* pointer);

/*
* function: unshift(List* list, int value) adds new element in the beginning of the list
* arguments: List* list (pointer to the head of the list)
			 int value (new value)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int unshift(List* list, int value);

/*
* function: shift(List* list, int* pointer) gets the first element of the list
* arguments: List* list (pointer to the head of the list)
			 int* pointer (address where to put the element)
* returning values:
					0 if opetation successfully complited
					1 if operation didn't successfully complited
*/
int shift(List* list, int* pointer);

/*
* function: print(List* list) prints list
* arguments: List* list (pointer to the head of the list)
* returning values: none
*/
void print(List* list);

/*
* function: print(List* list) prints list in reverse
* arguments: List* list (pointer to the head of the list)
* returning values: none
*/
void reverseprint(List* list);
