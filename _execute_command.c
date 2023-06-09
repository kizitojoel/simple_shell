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
	char *path;
	ssize_t nbytes;
	/* Not a valid file path */
	path = _compute_path(args[0]);
	if (path == NULL)
		return;
	args[0] = path;
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
		execve(path, args, env);
		printf("Unknown command\n");
		exit(0);
	}
	else
	{
		/* Close the write end of the pipe */
		close(pipefd[1]);
		/* Read from the pipe and print the output */
		while ((nbytes = read(pipefd[0], buffer, sizeof(buffer))) > 0)
		{
			write(STDOUT_FILENO, buffer, nbytes);
		}
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
	char **test = NULL;
	char *test_mem = NULL;
	int i = 0;
	int loop_count = 0;
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
		test = (char **)realloc(sub_args, (count + 2) * sizeof(char *));
		if (test == NULL)
		{
			for (loop_count = 0; sub_args[loop_count] != NULL; loop_count++)
				free(sub_args[loop_count]);
			free(sub_args);
			fprintf(stderr, "Memory allocation failed.\n");
			return;
		}
		else
			sub_args = test;
		test_mem = (char *) malloc(MAX_LENGTH * sizeof(char));
		if (test_mem == NULL)
		{
			for (loop_count = 0; sub_args[loop_count] != NULL; loop_count++)
				free(sub_args[loop_count]);
			free(sub_args);
			fprintf(stderr, "Memory allocation failed.\n");
			return;
		}
		else
			sub_args[count] = test_mem;
		strcpy(sub_args[count], args[i]);
		count++;
	}
	sub_args[count] = NULL;
	_execute_command(sub_args, env);
	for (loop_count = 0; loop_count < count; loop_count++)
		free(sub_args[loop_count]);
	free(sub_args);
}
