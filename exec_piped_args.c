#include "main.h"

/**
 * exec_piped_args - Function where the piped system commands is executed
 *
 * @parsed: Passed in during function call
 * @parsedpipe: Passed in during function call
 *
 *
 * Return: void
 */

void exec_piped_args(char **parsed, char **parsedpipe)
{
	/* 0 is read end, 1 is write end */
	int pipefd[2];

	pid_t pid1, pid2;

	if (pipe(pipefd) < 0)
	{
		printf("\nPipe could not be initialized");
		return;
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		printf("\nCould not fork!");
		return;
	}
	if (pid1 == 0)
	{
		/* Child 1 executing.. */
		/* It only needs to write at the write end */
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (execvp(parsed[0], parsed) < 0)
		{
			printf("\nCould not execute command 1..");
			exit(0);
		}
	}
	else
	{
		/* Parent executing */
		pid2 = fork();
		if (pid2 < 0)
		{
			printf("\nCould not fork");
			return;
		}
		/* Child 2 executing.. */
		/* It only needs to read at the read end */
		if (pid2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0)
			{
				printf("\nCould not execute command 2..");
				exit(0);
			}
		}
		else
		{
			/* parent executing, waiting for two children */
			wait(NULL);
			wait(NULL);
		}
	}
}

/**
 * pid1_is_zero - Executes if pid1 equals zero
 * @pipefd: Passed in during function call
 * @parsed: Passed in during function call
 * Return: void
 */

void pid1_is_zero(int *pipefd, char **parsed)
{
	/* Child 1 executing.. */
	/* It only needs to write at the write end */
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);

	if (execvp(parsed[0], parsed) < 0)
	{
		printf("\nCould not execute command 1..");
		exit(0);
	}
}

/**
 * pid1_not_zero - Executes if pid1 is not zero
 * @pipefd: Passed in during function call
 * @parsedpipe: Passed in during function call
 * Return: void
 */

void pid1_not_zero(int *pipefd, char **parsedpipe)
{
	pid_t pid2;
	/* Parent executing */
	pid2 = fork();

	if (pid2 < 0)
	{
		printf("\nCould not fork");
		return;
	}

	/* Child 2 executing.. */
	/* It only needs to read at the read end */
	if (pid2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		if (execvp(parsedpipe[0], parsedpipe) < 0)
		{
			printf("\nCould not execute command 2..");
			exit(0);
		}
	}
	else
	{
		/* parent executing, waiting for two children */
		wait(NULL);
		wait(NULL);
	}
}
