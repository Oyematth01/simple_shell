#include "shell.h"
#include <stdlib.h>

/**
 * exit_shell - Exits the shell
 * @args: Array of arguments
 */
void exit_shell(char **args)
{
    if (args[1] != NULL) {
        exit(atoi(args[1]));
    } else {
        exit(0);
    }
}
