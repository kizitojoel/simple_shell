#include "main.h"

/**
 * _validate_path - checks whether a path points to a file or not
 * @path: the string to check
 * Return: 0 if the string is a valid file path else -1
 */
int _validate_path(char *path)
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
