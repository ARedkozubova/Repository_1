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
* Fill the list with integer numbers in range [0, number]
* Params: list - pointer to the list, number - int value
* Return none
*/
void fill_list(List *list, int number);

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
* Test for checking function list_new
*/
int test_new();

/*
* Test for checking function push
*/
int test_push();

/*
* Test for checking function list_delete
*/
int test_delete();

/*
* Test for checking function pop
*/
int test_pop();

