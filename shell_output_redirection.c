#include "shell.h"

/**
 * output_redirection - redirects output to a file
 * @args: array of arguments
 * @output_file: name of the output file
 */
void output_redirection(char **args, char *output_file)
{
    pid_t pid;
    int fd;

    pid = fork();
    if (pid == 0)
    {
        fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);

        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        wait(NULL);
    }
}
