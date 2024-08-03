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
void execute_command(char **args);
void handle_signal(int sig);
void change_directory(char **args);
void print_help(void);
char *read_line(void);
char **split_line(char *line);
void execute_background(char **args);

#endif /* SHELL_H */
