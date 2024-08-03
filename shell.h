#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

/* Function prototypes */
void change_directory(char **args);
void execute_command(char **args);
char *read_line(void);
char **split_line(char *line);
void execute_background(char **args);
void handle_signal(int signal);
void print_env(void);
void print_help(void);
void exit_shell(char **args)
#endif /* SHELL_H */
