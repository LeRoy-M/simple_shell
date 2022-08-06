#include "main.h"

/**
 * process_string - Function to process the string
 *
 * @str: Commandline passed arguments
 * @parsed: No. of parsed commands
 * @parsedpipe: No. of parsed pipes
 *
 * Return: '0' or '1' or '2'
 */

int process_string(char *str, char **parsed, char **parsedpipe)
{
	char *strpiped[2];
	int piped;

	piped = 0;
	piped = parse_pipe(str, strpiped);

	if (piped)
	{
		parse_space(strpiped[0], parsed);
		parse_space(strpiped[1], parsedpipe);
	}
	else
	{
		parse_space(str, parsed);
	}

	if (cmd_handler(parsed))
		return (0);
	else
		return (1 + piped);
}
