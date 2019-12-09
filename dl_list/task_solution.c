#include "dl_list.h"
#include <stdio.h>

 int brackets(char *sequence)
{
	List *list = list_new();
	int current, *bracket = NULL;
	int i = 0, n = strlen(sequence);
	for (i = 0; i < n; i++)
	{
		if (sequence[i] != '{' || sequence[i] != '(' || sequence[i] != '}' || sequence[i] != '}')
		{
			printf("ERROR: input is invalid!\n");
			return -1;
		}
		if (sequence[i] == '{' || sequence[i] == '(')
		{
			if (sequence[i] == '{')
				current = 1;
			else if (sequence[i] == '(')
				current = 2;
			push(list, current);
		}
		if (sequence[i] == '}' || sequence[i] == ')')
		{
			pop(list, bracket);
			if ((sequence[i] == '}') && (*(bracket) != 1))
			{
				printf("Sequence of brackets is not correct!\n");
				return -1;
			}
			if ((sequence[i] == ')') && (*(bracket) != 2))
			{
				printf("Sequence of brackets is not correct!\n");
				return -1;
			}
		}

	}
	printf("The sequence of brackets is correct))\n");
	return 0;
}