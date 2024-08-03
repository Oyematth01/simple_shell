#include "shell.h"

/**
 * handle_signal - Handles the SIGINT signal
 * @sig: The signal number
 */
void handle_signal(int sig)
{
    if (sig == SIGINT)
    {
        write(STDOUT_FILENO, "\n$ ", 3);
    }
}
