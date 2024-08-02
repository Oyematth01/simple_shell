#include "shell.h"

void print_help(void)
{
    printf("Shell Help:\n");
    printf("Built-in commands:\n");
    printf("  cd [directory] - Change the current directory to [directory]\n");
    printf("  exit - Exit the shell\n");
    printf("  env - Print the environment variables\n");
    printf("  help - Print this help message\n");
}

/**
 * main - Entry point of the shell handling help built-in command
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

        if (strcmp(args[0], "help") == 0)
        {
            print_help();
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