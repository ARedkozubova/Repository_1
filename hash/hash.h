#pragma once

typedef struct _Node
{
	struct _Node* next;
	char* family;
	long long int number;
} Node;

typedef struct _List
{
	int size;
	Node* head;
} List;

List* Alpha[26];

/*
* function hash_function(char* Letter)
* arguments: pointer to family
* returning values: none
*/
int hash_function(char* Letter);

/*
* function List* list_new() creates new single linked list
* arguments: none;
* returning value: pointer to empty single lincked list
*/
List* list_new();

/*
* THIS FUNCTION MUST BE USED IN MAIN()
* function add_lists() creates empty hash map 
* arguments: none
* returning value: none
*/
void add_lists(); 

/*
* function insert(char* family, long long number)
* arguments: pointer to family, phone number
* returning values
* prints if the number was added or changed
*/
int insert(char* family, long long int number);

/*
* function аштв(char* family)
* arguments: phone number
* returning values
* prints number for a person if it exists
*/
int find(char* family);
