#include "main.h"

/**
 * ls - lists the files that are present in the folder specified in input
 *
 * Description: lists current files and folders separated by space
 */
int ls(char *path)
{
	DIR *dp;
	struct dirent *dir_entry;
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
		while (*str_buffer != '\0')
		{
			_putchar(*str_buffer);
			str_buffer++;
		}
		_putchar(' ');
		dir_entry = readdir(dp);
	}
	_putchar('\n');
	closedir(dp);
	return (0);
}

int main(int argc, char __attribute__ (( unused )) **argv)
{
	if (argc == 1)
		ls(".");
	return (0);
}
