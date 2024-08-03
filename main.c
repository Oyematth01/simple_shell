#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *line = NULL;  /* Line buffer */
    size_t len = 0;  /* Buffer size */
    ssize_t nread;  /* Number of characters read */
    pid_t pid;  /* Process ID */
    int status;  /* Status of child process */

    while (1)
    {
        display_prompt();

        /* Read the command from standard input */
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            if (feof(stdin))
            {
                /* Handle Ctrl+D (EOF) */
                printf("\n");
                break;
            }
            else
            {
                perror("getline");
                continue;
            }
        }

        /* Remove the newline character at the end */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        /* Fork a child process */
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }

        if (pid == 0)
        {
            /* In the child process */
            execute_command(line);
        }
        else
        {
            /* In the parent process */
            wait(&status);
        }
    }

    free(line);
    return (0);
}
