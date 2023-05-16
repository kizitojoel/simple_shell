#include "main.h"

/**
 * execute_command - executes the passed command with the passed args
 * @args: the args to pass to the execve
 */
void _execute_command(char **args)
{
    pid_t subprocess;
    int status;

    subprocess = fork();
    if (subprocess == -1)
        perror("fork failed!\n");
    else if (subprocess == 0)
    {
        printf("calling execve");
        execve(args[0], args, NULL);
        printf("Unknown command\n");
        exit(0);
    }
    else
        wait(&status);

}

