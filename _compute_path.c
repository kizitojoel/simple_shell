#include "main.h"

#define MAX_PATH_LENGTH 1024

/**
 * search_command - searched a command in the system's path
 * @command: the command to search
 * @result: variable to store the path if found
 * Return: 0 if success else -1
 */
int search_command(const char *command, char *result)
{
	char *path = getenv("PATH");
	char *path_copy;
	char *dir;
	char file_path[MAX_PATH_LENGTH];

	if (path == NULL)
	{
		printf("Error: PATH environment variable not found.\n");
		return (-1);
	}

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		snprintf(file_path, sizeof(file_path), "%s/%s", dir, command);

		if (access(file_path, X_OK) == 0)
		{
			strncpy(result, file_path, MAX_PATH_LENGTH);
			free(path_copy);
			return (0);
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);

	return (-1);
}

/**
 * _compute_path - looks up the command in the system path
 * @path: the string to check
 * Return: the path if it exists else NULL
 */
char *_compute_path(char *path)
{
	struct stat path_stat;
	char *result = malloc(sizeof(char) * MAX_PATH_LENGTH);

	if (stat(path, &path_stat) != 0)
	{
		if (search_command(path, result) != 0)
		{
			printf("%s: command not found\n", path);
			return (NULL);
		}
		else
			return (result);
	}
	if (!S_ISREG(path_stat.st_mode))
	{
		printf("%s is not a file..\n", path);
		return (NULL);
	}
	return (path);
}
