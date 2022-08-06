#include "main.h"

/**
 * parse_pipe - function for finding pipe
 *
 * @str: Input arguments
 * @strpiped: Pointer to array
 *
 * Return: '0' or '1'
 */

int parse_pipe(char *str, char **strpiped)
{
	int i;

	for (i = 0; i < 2; i++)
	{
		strpiped[i] = strsep(&str, "|");
		if (strpiped[i] == NULL)
			break;
	}

	if (strpiped[1] == NULL)
		return (0); /* no pipe is found. */

	return (1);
}
