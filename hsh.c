#include "main.h"

/**
 * print_path - prints the current working directory
 */
void print_path(void)
{
	_puts("$ ");
}

/**
 * main - entry point for the simple shell program
 * Return: 0 if success else -1
 */
int main(void)
{
	ssize_t length = 0;
	size_t index, bufsize, __attribute__((unused)) fd = 0;
	char **args, *token, *path, *line = NULL;/* cwd[1024];*/
	int count = 0;

	/**
	fd = open("cwd.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	getcwd(cwd, sizeof(cwd));
	write(fd, cwd, sizeof(cwd) - 1);
	*/
	while (length != -1)
	{
		if (isatty(STDIN_FILENO))
			print_path();
		length = getline(&line, &bufsize, stdin);

		_strip(line);
		if (line[0] == '\0' || line[0] == '\n')
			continue;
		for (index = 0; index < strlen(line); index++)
			if (line[index] == ' ' || index == strlen(line) - 1)
				count++;
		args = (char **) malloc((count + 1) * sizeof(char *));
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
		if (strcmp(path, "exit") == 0)
			break;
		execute_command(args, environ);
		if (!isatty(STDIN_FILENO))
			break;
	}
	free(args);
	free(line);
	return (0);
}
