#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * change_directory - Changes the current working directory
 * @args: Array of arguments
 *
 * Description: This function changes the current working directory
 * to the directory specified in the args array. If no directory
 * is specified, it prints an error message.
 */
void change_directory(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}
