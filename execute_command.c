#include "shell.h"

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;
    char *args[] = {command, NULL};

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        if (execve(command, args, environ) == -1)
        {
            perror(command);
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
