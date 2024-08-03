#include "shell.h"

/**
 * main - Entry point of the shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *command;
    ssize_t nread;

    signal(SIGINT, handle_signal);

    while (1)
    {
        prompt();
        command = read_command();
        if (command == NULL)
        {
            free(command);
            break;
        }

        if (command[0] != '\0')
        {
            execute_command(command);
        }
        free(command);
    }
    return (0);
}
