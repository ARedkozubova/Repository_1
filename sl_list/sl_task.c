/*
File: sl_task.c
Task 1.2
Created on 09.12.19
Author: Kasapenko Natalya
*/

#include <stdio.h>
#include <stdlib.h>
#include "sl_list.h"
#include "task.h"

/*
creates single linked list of N elements that decrease from N to 1
*/
pslist first_integers(int N)
{
	pslist List;
	List = slist_new();
	int i = 0;
		for (i = 1; i < N+1; i++)
		{
			slist_insert(List, i);
		}
		slist_print(List);
		return List;
}
