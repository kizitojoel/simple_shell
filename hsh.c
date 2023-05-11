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
	int status;

	subprocess = fork();
	if (subprocess == -1)
		perror("fork failed!\n");
	else if (subprocess == 0)
	{
		execve(args[0], args, NULL);
		printf("Unknown command\n");
		exit(0);
	}
	else
		wait(&status);

}

void remove_spaces(char *str)
{
	int length = strlen(str);
	if (length > 0)
	{
		while (length > 0 && (str[length - 1] == ' ' || str[length - 1] == '\n' || str[length - 1] == '\r'))
		{
			str[length - 1] = '\0';
			length--;
		}
	}
}

/**
 * main - entry point for the simple shell program
 * Return: 0 is success else -1
 */
int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t length = 0;
	size_t index, len;
	char **args, *token, *path;
	int count = 0;

	while (length != -1)
	{
		printf("$");
		length = getline(&line, &bufsize, stdin);
		remove_spaces(line);
                len = strlen(line);
		if (line[0] == '\0' || line[0] == '\n')
			continue;
		for (index = 0; index < len; index++)
			if (line[index] == ' ' || index == len - 1)
				count++;

		args = (char **) malloc(count * sizeof(char *));
		token = strtok(line, " ");
		index = 0;
		count = 0;
		while (token != NULL)
		{
			args[index] = token;
			token = strtok(NULL, " ");
			index++;
		}

		path = args[0];
		if (validate_path(path) == -1)
			continue;

		execute(args);

		free(args);
		free(line);

	}
	return (0);
}
