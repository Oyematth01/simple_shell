#include "shell.h"

/**
 * input_redirection - redirects input from a file
 * @args: array of arguments
 * @input_file: name of the input file
 *
 * Description: This function forks a new process and redirects
 * the input of the command specified in args from the given input_file.
 * The child process will replace its standard input with the input_file
 * and execute the command. If forking or opening the file fails, an error
 * message is printed.
 */
void input_redirection(char **args, char *input_file)
{
    pid_t pid;
    int fd;

    pid = fork();
    if (pid == 0)
    {
        fd = open(input_file, O_RDONLY);
        if (fd < 0)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDIN_FILENO);
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
