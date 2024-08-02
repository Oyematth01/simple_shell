#include "shell.h"

/**
 * print_env - prints the environment variables
 *
 * Description: This function iterates through the environment variables
 * and prints each one to the standard output.
 */
void print_env(void)
{
    extern char **environ;
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

/**
 * main - Entry point of the shell handling env built-in command
 *
 * Description: This function provides a simple shell interface that can handle
 * the built-in `env` command. It reads input from the user, tokenizes it, and
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

        if (args[0] == NULL)
        {
            continue; /* Empty command, prompt again */
        }

        if (strcmp(args[0], "env") == 0)
        {
            print_env();
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
