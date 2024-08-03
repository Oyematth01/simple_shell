#include "shell.h"
#include <signal.h>
#include <stdio.h>

/**
 * handle_signal - Handles the SIGINT signal (Ctrl+C)
 * @signal: The signal number
 */
void handle_signal(int signal)
{
    (void)signal;
    printf("\n");
}
