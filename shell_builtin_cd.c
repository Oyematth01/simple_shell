#include "shell.h"

/**
 * execute_background - executes a command in the background
 * @args: array of arguments
 *
 * Description: This function forks a new process to execute a given command
 * in the background. The child process is detached from the terminal and 
 * executes the command using execvp. If the fork fails, an error message is
 * printed.
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
