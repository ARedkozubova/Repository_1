#include "sl_list.h"

/*
* test1()
* checks work of function slist_new()
* returning values: 0 if works Ok
				    1 if found an error
*/
int test1();

/*
* test2()
* checks work of function slist_insert()
* returning values: 0 if works Ok
					1 if found an error
*/
int test2();

/*
* test3() 
* checks variable list->list_size
* returning values: 0 if works Ok
					1 if found an error
*/
int test3();

/*
* test4()
* checks work of function slist_remove()
* * returning values: 0 if works Ok
					1 if found an error
*/
int test4();

/*
* test5()
* checks work of function list_delete();
* returning values: none (as function list_delete() returns void)
*/
void test5();

/*
* test6() 
* checks workk of function print()
* returning values: none (as function print() returns void)
*/
void test6();

/*
Additional function slist_find(pslist list, int value)
arguments: pslist list(pointer to the list), int value(searched element)
returning value: 1 if element value exists in the list
				 0 if element value doesn't exist in the list
*/
int slist_find(pslist list, int value);

/*
* function run_all_tests()
* runs all int tests
* returning values: none
*/
void run_all_tests();
