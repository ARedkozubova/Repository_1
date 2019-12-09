#pragma once
#include <stdio.h>
#include < string.h > 
#include "hash.h"

//определяет первую букву введенного слова
int hash_function(char* Surname)
{
	char first = Surname[0];
	int Number;
	Number = (int)(first)-65;
	if (Number >=0 && Number<=26)
		return Number;
	else
	{
		printf("Incorrect format of family. Use capital Latin script!");
		return 1;
	}
}

List* list_new()
{
	List* NewList = (List*)malloc(sizeof(List));
	NewList->size = 0;
	NewList->head = NULL;
	return NewList;
}

void add_lists()
{
	int i = 0;
	for (i = 0; i < 26; i++)
	{
		List* p;
		p = list_new();
		Alpha[i] = p;
	}
}

int insert(char* family, long long int number)
{
	int Letter = hash_function(family);
	if (Alpha[Letter]->size == 0) //if the list is empty
	{
		Node* NewNode = (Node*)malloc(sizeof(Node));
		if (NULL == NewNode)
		{
			printf("function insert(): Collocation error!");
			return 1;
		}
		NewNode->next = NULL;
		NewNode->family = family;
		NewNode->number = number;
		Alpha[Letter]->head = NewNode;
		Alpha[Letter]->size = 1;
	}
	 //if list is not empty
	else 
	{
		Node* NewNode = (Node*)malloc(sizeof(Node));
		Node* current = Alpha[Letter]->head;
		if (NULL == NewNode)
		{
			printf("function insert(): Collocation error!");
			return 1;
		}

		int i;
		int exists = 0;
		for (i = 0; i < Alpha[Letter]->size; i++)  //if this family already exists
		{
			if (strcmp(current->family, family) == 0) 
			{
				long long int OldValue;
				OldValue = current->number;
				current->number = number;
				exists = 1;
				printf("\nPhone number for person %s Changed.Old number = %lli", current->family, OldValue);
			}
			current = current->next;
		}

		if (exists == 0) //if this family is new
		{
			Node* tmp;
			tmp = Alpha[Letter]->head;
			NewNode->next = NULL;
			NewNode->family = family;
			NewNode->number = number;
			Alpha[Letter]->size = Alpha[Letter]->size + 1;
			while (NULL != tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = NewNode;
			printf("\n New record for %s with number %lli was added", tmp->family, tmp->number);
		}

	}
	return 0;
}

int find(char* family)
{
	int Letter = hash_function(family);
	Node* tmp = Alpha[Letter]->head;
	int i;
	int exists = 0;
	for (i = 0; i < Alpha[Letter]->size; i++)
	{
		if (tmp->family == family)
		{
			exists = 1;
			printf("\nTelephone number for %s is %lli", family ,tmp->number);
		}
		tmp = tmp->next;
	}
	if (exists == 0)
		printf("\n Person %s wasn't found in the book", family);
	return 0;
}
