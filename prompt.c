#include "shell.h"

/**
 * prompt - Displays the shell prompt
 */
void prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}
