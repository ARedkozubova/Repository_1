/*
 * File: dl_list
 * Brief: Double linked list header
 * Author: Anastasia Redkozubova
 * Created on: 18.11.2019
 * (c) MIPT
*/


#pragma once
typedef struct _LIST_ENTRY LIST_ENTRY;

typedef struct _LIST
{
	LIST_ENTRY *first;
} LIST;

struct _LIST_ENTRY
{
	int value;
	LIST_ENTRY *prev;
	LIST_ENTRY *next;
};

LIST *list_new();

void list_delete(LIST *list);

int push(LIST *list, int value);

int pop(LIST *list, LIST_ENTRY *entry);

int unshift(LIST *list, int value);
