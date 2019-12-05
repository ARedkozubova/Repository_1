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
	return queue;
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
	elem->next = NULL;
	if (NULL == queue->head && NULL == queue->tail)
	{
		queue->size = 1;
		queue->head = elem;
		queue->tail = elem;
	}
	else if(queue->head == queue->tail)
	{
		queue->head->next = elem;
		queue->tail = elem;
		queue->size++;
	}
	else
	{
		queue->tail->next = elem;
		queue->tail = elem;
		queue->size++;
	}
	return 0;
}

/*
* Remove first element from the queue
*/
int pop_element(pqueue queue)
{
	if (queue->size == 0)
	{
		printf("ERROR: removing element from the empty queue!\n");
		return NULL;
	}
	pelement elem = queue->head;
	queue->head = queue->head->next;
	return elem->value;
}

/*
* Print the queue
*/
void print_queue(pqueue queue)
{
	if (NULL == queue->head && NULL == queue->tail)
	{
		printf("Sorry, queue is empty...\n");
	}
	else
	{
		pelement current = queue->head;
		while (current != queue->tail)
		{
			printf("%d <- ", current->value);
			current = current->next;
		}
		printf("%d\n", current->value);
	}
}
