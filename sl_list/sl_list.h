/*
 * This file is slist.h
 * Single linked list
 *
 */

#pragma once

 // Forward declaration
typedef struct slist_entry *pslist_entry;
typedef struct slist *pslist;

struct slist_entry
{
	pslist_entry next;
	int value;
};

struct slist
{
	int list_size; // sugar
	pslist_entry head;
};

/*
 * Creates an empty list
 * Params: none
 * Returns pointer to the list
 */
pslist slist_new(void);

/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */
void slist_delete(pslist list);

/*
 * Insert element in the beginning of the list
 * Params: list - pointer to the list, element - int value
 * Returns if the insertion is correct or not
 */
int slist_insert(pslist list, int value);

/*
 * Remove from the list all the element with given value
 * Params: list - pointer to the list, element - int value
 * Returns if the removing is correct or not
 */
int slist_remove(pslist list, int value);

/*
 * Print values of the element in the list
 * Params: list - pointer to the list
 * Returns none
 */
void slist_print(pslist list);