#include "shell.h"

/**
 * main - Entry point of the shell handling exit built-in command
 *
 * Description: This function provides a simple shell interface that can handle
 * the built-in `exit` command. It reads input from the user, tokenizes it, and
 * executes the appropriate commands. The shell runs in an infinite loop until
 * terminated.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *line = NULL;
    char *args[64];
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;
    int i;

    while (1)
    {
        printf("$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            perror("getline");
            exit(EXIT_FAILURE);
        }

        line[nread - 1] = '\0'; /* Remove newline character */
        args[0] = strtok(line, " ");
        for (i = 1; i < 64; i++)
        {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL)
                break;
        }

        if (args[0] == NULL)
        {
            continue; /* Empty command, prompt again */
        }

        if (strcmp(args[0], "exit") == 0)
        {
            free(line);
            exit(0);
        }

        pid = fork();
        if (pid == 0)
        {
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
            wait(&status);
        }
    }
    free(line);
    return (0);
}
