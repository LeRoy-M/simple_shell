#include "main.h"

/**
 * exec_args - Function where the system command is executed
 *
 * @parsed: Parsed arguments
 *
 * Return: void
 */

void exec_args(char **parsed)
{
	/* Forking a child */
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("\nFailed to fork child process!");
		return;
	}
	else if (pid == 0)
	{
		if (execvp(parsed[0], parsed) < 0)
		{
			printf("\nCould NOT execute command!");
		}
		exit(0);
	}
	else
	{
		/* waiting for child to terminate */
		wait(NULL);
		return;
	}
}
