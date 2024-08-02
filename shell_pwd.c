#include "shell.h"

/**
 * print_working_directory - prints the current working directory
 */
void print_working_directory(void)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("pwd");
    }
}
