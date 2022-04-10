# pipex
This project will let you discover in detail a UNIX mechanism that you already know by using it in your program.

Pipex is an individual project at 42 that requires us to create a program that simulates the behavior of the shell pipe, receiving a file or
reading from the STDIN and redirecting to a sequence of commands that will be written to the output file.
To build the program it is necessary to create child processes using fork() communicating with the parent process through pipe(),
manipulating the environment variable, testing if the command exists or has execution permission, for example,
printing errors to STDERR when necessary, returning the correct status code.
