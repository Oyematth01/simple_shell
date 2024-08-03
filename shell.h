#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define PROMPT "#cisfun$ "

void display_prompt();
void execute_command(char *command);

#endif /* SHELL_H */
