/*
 * This file is slist.c
 * Single linked list implementation
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "sl_list.h"

/* Create new empty list */
pslist slist_new(void)
{
	pslist list = malloc(sizeof(struct slist));
	if (NULL == list)
	{
		printf("ERROR: failed allocation of memory for new list!\n");
		return NULL;
	}
	list->list_size = 0;
	list->head = NULL;

	return list;
}

/* For each element free memory */
void slist_delete(pslist list)
{}

/* Allocate the element
   Put at the end */
int slist_insert(pslist list, int value)
{
	pslist_entry pnew = malloc(sizeof(struct slist_entry));
	if (NULL == pnew)
	{
		printf("ERROR: failed allocation of memory for new element!\n");
		return -1;
	}
	pnew->next = list->head;
	pnew->value = value;
	printf("New element: %d\n", pnew->value);
	list->head = pnew;
	list->list_size++;
	return 0;
}

/* Go through the list, remove if value is equal */
int slist_remove(pslist list, int value)
{
	pslist_entry current = list->head;
	pslist_entry prev = NULL;
	if (NULL == current)
	{
		printf("ERROR: removing element from empty list!\n");
		return -1;
	}

	while (NULL != current)
	{
		if (current->value == value)
		{
			while (prev->next != current)
			{
				prev = prev->next;
			}

			prev->next = current->next;
			free(current);
			if (NULL != current)
			{
				printf("ERROR: memory was not freed!\n");
				return -2;
			}
		}
	}
}

/* For each element print in value */
void slist_print(pslist list)
{
	pslist_entry current = list->head;
	if (NULL == current)
	{
		printf("Sorry...the list is empty.\n");
	}
	else
	{
		while (NULL != current->next)
		{
			printf("%d -> ", current->value);
			current = current->next;
		}
		printf("%d\n", current->value);
	}

}