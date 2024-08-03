#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command)
{
    char *argv[2];  /* Argument vector */

    argv[0] = command;
    argv[1] = NULL;

    execve(command, argv, NULL);

    /* If execve returns, it must have failed */
    fprintf(stderr, "%s: No such file or directory\n", command);
    exit(EXIT_FAILURE);
}
