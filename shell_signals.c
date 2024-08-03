#include "shell.h"

/**
 * handle_signal - handles the SIGINT signal (Ctrl+C)
 * @sig: signal number
 *
 * Description: This function handles the SIGINT signal by printing
 * a newline and the shell prompt (`$ `) when the signal is received.
 */
void handle_signal(int sig)
{
    if (sig == SIGINT)
    {
        printf("\n$ ");
        fflush(stdout);
    }
}

/**
 * main - Entry point of the shell handling signals
 *
 * Description: This function provides a simple shell interface
 * that handles the SIGINT signal to interrupt commands. It reads
 * input from the user, tokenizes it, and executes the command
 * using execvp. The shell runs in an infinite loop until terminated.
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
