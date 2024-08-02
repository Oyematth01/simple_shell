#include "shell.h"

/**
 * change_directory - changes the current working directory
 * @args: array of arguments
 */
void change_directory(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "cd: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
        }
    }
}
