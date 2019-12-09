#pragma once
#include <stdio.h>
#include "hash.h"

int main()
{
	char* St = NULL;
	char* N1 = NULL;
	char* N2 = NULL;

	N1 = (char*)malloc(10);
	St = (char*)malloc(10);
	N2 = (char*)malloc(10);

	St = "Ivanov";
	N1 = "Tupoi";
	N2 = "Tdfjk";
//	printf("%s", St);
//	scanf_s("%10s", St, sizeof(char)*10);
//	scanf("%s", St);
//	gets(St);
//	printf("%d", hash_function(St));
	add_lists();
	insert(St, 8999765);
	insert(N1, 7777777);
	find(St);
	find(N1);
	find(N2);
	insert(St, 900000);
	return 0;
}
