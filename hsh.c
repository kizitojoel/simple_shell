#include "main.h"

/**
 * main - entry point for the simple shell program
 * Return: 0 if success else -1
 */
int main(void)
{
	ssize_t length = 0;
	size_t index, bufsize, fd = 0;
	char **args, *token, *path, *line = NULL, cwd[1024];
	int count = 0;

	fd = open("cwd.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	getcwd(cwd, sizeof(cwd));
	write(fd, cwd, sizeof(cwd) - 1);
	while (length != -1)
	{
		printf("%s$ ",_getcwd());
		length = getline(&line, &bufsize, stdin);
		_strip(line);
		if (line[0] == '\0' || line[0] == '\n')
			continue;

		for (index = 0; index < strlen(line); index++)
			if (line[index] == ' ' || index == strlen(line) - 1)
				count++;

		args = (char **) malloc(count * sizeof(char *) + 1);
		token = strtok(line, " ");
		index = 0;
		count = 0;
		while (token != NULL)
		{
			args[index] = token;
			token = strtok(NULL, " ");
			index++;
		}
		args[index] = NULL;
		path = args[0];
		if (strcmp(path, "exit") == 0) break;
		if (validate_path(path) == -1)
			continue;

		execute_command(args);

	}
	free(args);
	free(line);
	return (0);
}
