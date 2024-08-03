#include "shell.h"

/**
 * handle_signal - handles signals
 * @signal: signal number
 */
void handle_signal(int signal)
{
    if (signal == SIGINT)
    {
        printf("\nCaught SIGINT signal. Use 'exit' to quit the shell.\n");
    }
}

/**
 * setup_signal_handling - sets up signal handling
 */
void setup_signal_handling(void)
{
    struct sigaction sa;

    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
}
