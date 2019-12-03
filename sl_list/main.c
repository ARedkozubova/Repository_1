/*
 * File:  main.c
 * Brief: realisation of single linked list
 * Created on 01.12.2019
 * (c) MIPT 2019
 */
#include "sl_list.h"

int main()
{

	if (test1() == 0) printf("\ntest1:PASSED\n");
	else printf("test1:FAILED");

	if (test2() == 0) printf("\ntest2:PASSED\n");
	else printf("test2:FAILED");

	test3();
	test4();

	return 0;
}
