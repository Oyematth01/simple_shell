#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

/* Function prototypes */
void execute_command(char **args);
char *read_line(void);
char **split_line(char *line);
void execute_background(char **args);

/**
 * main - Entry point of the shell
 *
 * Return: Always 0 (success)
 */
int main(void)
{
    char *line;
    char **args;
    int status = 1;

    signal(SIGINT, handle_signal);

    do {
        printf("> ");
        line = read_line();
        args = split_line(line);

        if (args[0] == NULL) {
            /* Empty command, do nothing */
        } else if (strcmp(args[0], "cd") == 0) {
            change_directory(args);
        } else if (strcmp(args[0], "exit") == 0) {
            exit_shell(args);
        } else if (strcmp(args[0], "env") == 0) {
            print_env();
        } else if (strcmp(args[0], "help") == 0) {
            print_help();
        } else {
            execute_command(args);
        }

        free(line);
        free(args);
    } while (status);

    return (0);
}

/**
 * read_line - Reads a line of input from the user
 *
 * Return: The line read from input
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return (line);
}

/**
 * split_line - Splits a line into tokens
 * @line: The line to be split
 *
 * Return: An array of tokens
 */
char **split_line(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return (tokens);
}

/**
 * execute_command - Executes a command
 * @args: Array of arguments
 */
void execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Error forking */
        perror("fork");
    } else {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/**
 * handle_signal - Handles the SIGINT signal (Ctrl+C)
 * @signal: The signal number
 */
void handle_signal(int signal)
{
    (void)signal;
    printf("\n");
}
