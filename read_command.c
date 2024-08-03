#include "shell.h"

/**
 * read_command - Reads the command from the user
 *
 * Return: The command string
 */
char *read_command(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);
    if (nread == -1)
    {
        free(line);
        return (NULL);
    }

    line[nread - 1] = '\0'; /* Remove newline character */
    return (line);
}
