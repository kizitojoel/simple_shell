#include "main.h"

#define MAX_LENGTH 100

/**
 * _execute_command - calls the command and handles piping
 * @args: arguments to pass tio the command
 * @env: the environment variables from the hsh main function
 */
void _execute_command(char **args, char **env)
{
	pid_t current;
	int pipefd[2];
	char buffer[1024];
	ssize_t nbytes;
	/* Not a valid file path */
	if (_validate_path(args[0]) == -1)
		return;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	current = fork();
	if (current == -1)
		perror("fork failed!\n");
	else if (current == 0)
	{
		/* Close the read end of the pipe */
		close(pipefd[0]);
		/* Redirect the standard output to write to the pipe */
		dup2(pipefd[1], STDOUT_FILENO);
		execve(args[0], args, env);
		printf("Unknown command\n");
		exit(0);
	}
	else
	{
		/* Close the write end of the pipe */
		close(pipefd[1]);
		/* Read from the pipe and print the output */
		while ((nbytes = read(pipefd[0], buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, nbytes);
		close(pipefd[0]);
		/* Wait for the child to finish */
		wait(NULL);
	}
}

/**
 * execute_command - executes the passed command with the passed args
 * @args: the args to pass to the execve
 * @env: the environment variables
 */
void execute_command(char **args, char **env)
{
	char **sub_args = NULL;
	int i = 0;
	int numStrings = 0, count = 0;

	while (args[i] != NULL)
	{
		numStrings++;
		i++;
	}

	for (i = 0; i < numStrings; i++)
	{
		if (strcmp(args[i], "|") == 0)
		{
			_execute_command(sub_args, env);
			count = 0;
			continue;
		}
		sub_args = (char **)realloc(sub_args, (count + 1) * sizeof(char *));
		if (sub_args == NULL)
		{
			fprintf(stderr, "Memory allocation failed.\n");
			return;
		}
		sub_args[count] = (char *)malloc(MAX_LENGTH * sizeof(char));
		if (sub_args[count] == NULL)
		{
			fprintf(stderr, "Memory allocation failed.\n");
			return;
		}
		strcpy(sub_args[count], args[i]);
		count++;
	}
	_execute_command(sub_args, env);
	free(sub_args);
}
