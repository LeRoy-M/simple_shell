#include "main.h"

/**
 * parse_space - Function for parsing command words
 *
 * @str: From function call
 * @parsed: From function call
 *
 * Return: void
 */

void parse_space(char *str, char **parsed)
{
	int i;

	for (i = 0; i < MAXCOMD; i++)
	{
		parsed[i] = strsep(&str, " ");

		if (parsed[i] == NULL)
			break;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}
