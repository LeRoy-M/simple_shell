#include "main.h"

/**
 * get_input - Function to take input
 *
 * @str: Command line arguments from user
 *
 * Return: '0' or '1'
 */

int get_input(char *str)
{
	char *buf;

	buf = readline("");
	if (strlen(buf) != 0)
	{
		add_history(buf);
		strcpy(str, buf);
		return (0);
	}
	else
	{
		return (1);
	}
}
