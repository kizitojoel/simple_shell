#include "main.h"

/**
 * validate_path - check whether a path points to a file or not
 * @path: the string to check
 * Return: 0 if the string is a valid file path else -1
 */
int validate_path(char *path)
{
	struct stat path_stat;

	if (stat(path, &path_stat) != 0)
	{
		printf("%s: command not found\n", path);
		return (-1);
	}
	if (!S_ISREG(path_stat.st_mode))
	{
		printf("%s is not a file.\n", path);
		return (-1);
	}

	return (0);
}

/**
 * execute - executes the passed command with the passed args
 * @args: the args to pass to the execve
 */
void execute(char **args)
{
	pid_t subprocess;

	subprocess = fork();
	if (subprocess == -1) {
		perror("fork failed!\n");
		return;
	}
	else if (subprocess == 0) {
		execve(args[0], args, NULL);
		perror("execve\n");
		return;
	}
}

/**
 * main - entry point for the simple shell program
 * Return: 0 is success else -1
 */
int main() {
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t length;
	size_t index;
	char **args, *token, *path;
	int count = 0;

	printf("$");

        length = getline(&line, &bufsize, stdin);

	if(feof(stdin)){
		return (0);
	}

	if (length == -1)
	{
		printf("Error reading input.\n");
		return (-1);
	}

	for (index = 0; index < strlen(line); index++)
		if (line[index] == ' ')
			count++;

        args = (char**)malloc(count * sizeof(char*));
	token = strtok(line, " ");
	index = 0;
	while (token != NULL) {
		args[index] = token;
		token = strtok(NULL, " ");
		index++;
	}

	path = args[0];
	if (validate_path(path) == -1)
		return (-1);

	execute(args);

	free(args);
	free(line);
	return main();
}
