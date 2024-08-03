#include "shell.h"
#include <stdio.h>

/**
 * print_env - Prints the current environment variables
 */
void print_env(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
