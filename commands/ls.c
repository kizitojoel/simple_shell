#include "main.h"

/**
 * ls - lists the files that are present in the folder specified in input
 *
 * Description: lists current files and folders separated by space
 */
int ls(char *path)
{
	DIR *dp;
	struct dirent *dir_entry = NULL;
	char *str_buffer;

	if (path == NULL)
		return -1;
	dp = opendir(path);
	if (dp == NULL)
	{
		perror("Error: ");
		return -1;
	}
	dir_entry = readdir(dp);
	while (dir_entry)
	{
		str_buffer = dir_entry->d_name;
		dir_entry = readdir(dp);
		if (str_buffer[0] == '.')
			continue;
		while (*str_buffer != '\0')
		{
			_putchar(*str_buffer);
			str_buffer++;
		}
		_putchar(' ');
	}
	_putchar('\n');
	closedir(dp);
	return (0);
}

/**
 * main - main ls function
 * @argc: the number of arguments
 * @argv: the array of string pointers
 *
 * Return: 0 if successful
 */
int main(int argc, char __attribute__ (( unused )) **argv)
{
	int i = 0;
	int print_count = 0;
	char *argpointer = NULL;

	if (argc == 1)
		ls(".");
	if (argc == 2)
	{
		ls(argv[1]);
	}
	if (argc > 2)
	{
		for (i = 1; i < argc; i++)
		{
			argpointer = argv[i];
			for (print_count = 1; print_count < 10; print_count++)
				_putchar('=');
			while (*argpointer != '\0')
			{
				_putchar(*argpointer);
				argpointer++;
			}
			_putchar('\n');
			ls(argv[i]);
			_putchar('\n');
		}
	}
	return (0);
}
