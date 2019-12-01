/*
 * This file is slist.c
 * Single linked list implementation
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "sl_list.h"

pslist slist_new(void)
{
	return NULL;
}

/* For each element free memory */
void slist_delete(pslist list)
{ }

/* Allocate the element
   Put at the end */
int slist_insert(pslist list, int value)
{
	return 0;
}

/* Go through the list, remove if value is equal */
int slist_remove(pslist list, int value)
{
	return 0;
}

/* For each element print in value */
void slist_print(pslist list)
{ }