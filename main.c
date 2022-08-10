#include "main.h"

/**
 * main - Entry Point
 *
 * @ac: Command line argument count
 * @av: List of commandline arguments
 *
 * Return: Always 0
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char input_string[MAXLETR], *parsed_args[MAXCOMD];
	char *parsed_args_piped[MAXCOMD];
	int exec_flag;

	exec_flag = 0;
	while (1)
	{
		/* print shell line */
		print_cwd();

		/* take input */
		if (get_input(input_string))
			continue;
		/* process */
		exec_flag = process_string(input_string, parsed_args, parsed_args_piped);
		/* execflag returns zero if there is no command */
		/* or it is a builtin command, */
		/* 1 if it is a simple command */
		/* 2 if it is including a pipe. */

		/* execute */
		if (exec_flag == 1)
			exec_args(parsed_args);

		if (exec_flag == 2)
		{
			/* exec_piped_args(parsed_args, parsed_args_piped); */
			perror("Piping not available!");
			return (-1);
		}
	}
	return (0);
}
