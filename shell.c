#include "shell.h"

/**
 * main - Entry point of the shell
 *
 * Description: This function provides a simple shell interface that can
 * handle built-in commands like `cd`, `help`, and `exit`. It reads input
 * from the user, tokenizes it, and executes the appropriate commands. The
 * shell runs in an infinite loop until the `exit` command is given.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *args[64];
    pid_t pid;
    int status;

    signal(SIGINT, handle_signal);

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

        int i;
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

        if (strcmp(args[0], "cd") == 0)
        {
            change_directory(args[1]);
            continue;
        }
        else if (strcmp(args[0], "help") == 0)
        {
            print_help();
            continue;
        }
        else if (strcmp(args[0], "exit") == 0)
        {
            break;
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
