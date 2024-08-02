#include "shell.h"

/**
 * execute_background - executes a command in the background
 * @args: array of arguments
 */
void execute_background(char **args)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        setsid();
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        printf("Process running in background with PID: %d\n", pid);
    }
}
