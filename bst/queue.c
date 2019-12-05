/*
 * This file is queue.c
 * Queue for binary search tree implementation
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

 /*
  * Creates an empty queue
  */
pqueue new_queue()
{
	pqueue queue = malloc(sizeof(struct queue));
	if (NULL == queue)
	{
		printf("ERROR: failed allocation of memory for new queue!\n");
		return NULL;
	}
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
	return 0;
}

/*
* Insert new element in the queue
*/
int add_element(pqueue queue, int value)
{
	pelement elem = malloc(sizeof(struct element));
	if (NULL == elem)
	{
		printf("ERROR: failed allocation of memory for new element!\n");
		return -1;
	}
	elem->value = value;
	if (NULL == queue->head && NULL == queue->tail)
	{
		queue->size = 1;
		queue->head = elem;
		queue->tail = elem;
	}
	else
	{
		queue->tail = elem;
		queue->size++;
	}
	return 0;
}
