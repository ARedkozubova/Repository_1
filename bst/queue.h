#pragma once

/*
 * File: queue.h
 * Brief: Stack (supporting for binary search tree)
 * Author: Redkozubova Nastia
 * Created on: 05.12.2019
 * (c) MIPT
*/

typedef struct element *pelement;
typedef struct queue *pqueue;

struct element
{
	int value;
	pelement next;
};

struct queue 
{
	pelement head, tail;
	int size;
};

/*
 * Creates an empty queue
 * Params: none
 * Returns pointer to the queue
 */
pqueue new_queue();

/*
* Insert value in queue
* Params: queue - pointer to the queue, value - integer number
* Return: 0 if inserting was successful, -1 if inserting was unsuccessful
*/
int add_element (pqueue queue, int value);


/*
* Remove first element from queue
* Params: queue - pointer to the queue
* Return: value of the first element if removing was successful, NULL if removing was unsuccessful
*/
int pop_element(pqueue queue);

/*
* Print the queue
* Params: queue - pointer to the queue
* Return none
*/
void print_queue(pqueue queue);