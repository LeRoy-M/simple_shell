#include "main.h"

/**
 * cmd_handler - Function to execute builtin commands
 *
 * @parsed: Parsed input from command line
 *
 * Return: '0' or '1'
 */

int cmd_handler(char **parsed)
{
	int NoOfOwnCmds = 4, i, switchOwnArg = 0;
	char *ListOfOwnCmds[NoOfOwnCmds];
	char *username;

	ListOfOwnCmds[0] = "exit";
	ListOfOwnCmds[1] = "cd";
	ListOfOwnCmds[2] = "help";
	ListOfOwnCmds[3] = "hello";

	for (i = 0; i < NoOfOwnCmds; i++)
	{
		if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0)
		{
			switchOwnArg = i + 1;
			break;
		}
	}

	switch (switchOwnArg)
	{
	case 1:
		printf("\nGoodbye\n");
		exit(0);
	case 2:
		chdir(parsed[1]);
		return (1);
	case 3:
		/* open_help(); */
		return (1);
	case 4:
		username = getenv("USER");
		printf("\nHello %s.\nMind that this is not a place to play around.
		\nUse help to know more..\n", username);
		return (1);
	default:
		break;
	}

	return (0);
}
