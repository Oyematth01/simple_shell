#include "shell.h"

void execute_command(char *command) {
    char *argv[] = {command, NULL};
    execve(command, argv, NULL);
    // If execve returns, it must have failed
    fprintf(stderr, "%s: No such file or directory\n", command);
    exit(EXIT_FAILURE);
}
