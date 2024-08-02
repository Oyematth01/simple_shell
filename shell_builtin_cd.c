#include "shell.h"

void change_directory(char *path)
{
    if (chdir(path) != 0)
    {
        perror("chdir");
    }
}

/**
 * main - Entry point of the shell handling cd built-in command
 * Return: Always 0
 */
int main(void)
{
    char *line = NULL;
    char *args[64];
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

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
        for (int i = 1; i < 64; i++)
        {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL)
                break;
        }

        if (strcmp(args[0], "cd") == 0)
        {
            change_directory(args[1]);
            continue;
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
