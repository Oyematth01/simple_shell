#include "shell.h"

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1) {
        display_prompt();

        // Read the command from standard input
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            if (feof(stdin)) {
                // Handle Ctrl+D (EOF)
                printf("\n");
                break;
            } else {
                perror("getline");
                continue;
            }
        }

        // Remove the newline character at the end
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }

        // Fork a child process
        pid = fork();
        if (pid == -1) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // In the child process
            execute_command(line);
        } else {
            // In the parent process
            wait(&status);
        }
    }

    free(line);
    return 0;
}
