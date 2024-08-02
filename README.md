# Simple Shell

This is a simple UNIX command interpreter that replicates the core functionalities of a shell.

## Features
- Execute commands with arguments
- Handle signals
- Built-in commands: `cd`, `help`, `exit`
- Support for input redirection

## Built-in Commands
- `cd [directory]`: Change the current directory to [directory]
- `help`: Display help information
- `exit`: Exit the shell

## Compilation
Compile the shell using:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Usage
Run the shell:

sh
Copy code
./hsh

Authors
See AUTHORS file for a list of contributors.

ruby
Copy code

### AUTHORS
**Filename:** `AUTHORS`
```markdown
Matthew Oyelami