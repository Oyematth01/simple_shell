#include "shell.h"
#include <stdio.h>

/**
 * print_help - Prints help information for the shell
 */
void print_help(void)
{
	printf("Shell Help\n");
	printf("Available commands:\n");
	printf("cd [directory] - Change directory\n");
	printf("exit [status] - Exit shell with status\n");
	printf("help - Print this help message\n");
	/* Add more help information as needed */
}
