#include "main.h"

/**
 * print_cwd - Function to print Current Working Directory
 *
 * Return: void
 */

void print_cwd(void)
{
	char cwd[256];

	getcwd(cwd, sizeof(cwd));
	printf(":%s$ ", cwd);
}
