/*
 * File: dl_list
 * Brief: Double linked list header
 * Author: Anastasia Redkozubova
 * Created on: 03.12.2019
 * (c) MIPT
*/

#include "pch.h"
#include <stdio.h>
#include "dl_list.h"


/*
* Supporting function for other tests
* Check if element is in the list
* Params: list - pointer to the list, element - int value
* Return:
*		0 if element is not in the list
*		1 if element is in the list
*/
int find_element(List *list, int value);

/*
* Test for cheking function list_new
*/
int test_new();

/*
* Test for cheking function push
*/
int test_push();

