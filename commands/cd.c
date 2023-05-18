#include "main.h"

#define BUFFER_SIZE 4096

/**
 * main - changes the active directory
 * @argc: number of args
 * @argv: list of args
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int fd = 0;
	char *home_dir = getenv("HOME"), cwd[BUFFER_SIZE];
	char *cwd_file_name = "/cwd.txt";
	char cwd_file_path[BUFFER_SIZE];

	strcpy(cwd_file_path, getcwd(cwd, sizeof(cwd)));
	_strcat(cwd_file_path, cwd_file_name);
	if (argc == 1)
	{
		chdir(home_dir);
		return (0);
	}
	if (strcmp(argv[1], ".") == 0)
		return (0);
	if (argc > 2)
	{
		perror("bash: cd: too many arguments\n");
		return (-1);
	}
	chdir(_getcwd());
	if (chdir(argv[1]) != 0)
	{
		printf("bash: cd: hello: No such file or directory\n");
		return (-1);
	}
	getcwd(cwd, sizeof(cwd));
	fd = open(cwd_file_path, O_WRONLY | O_CREAT);
	write(fd, cwd, sizeof(cwd) - 1);

	return (0);
}
