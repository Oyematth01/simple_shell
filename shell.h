#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

/* Function prototypes */
void execute_command(char **args);
void handle_signal(int sig);
void change_directory(char *path);
void print_help(void);

#endif /* SHELL_H */
