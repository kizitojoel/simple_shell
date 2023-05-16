#include "main.h"

#define BUFFER_SIZE 4096

/**
 * _getcwd - get working directory
 * Return: The current directory path
 */
char *_getcwd()
{
	int fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	char *file_content = NULL;
	size_t content_size = 0;

	fd = open("/home/yk/Desktop/ALX/simple_shell/cwd.txt", O_RDONLY);

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		file_content = realloc(file_content, content_size + bytes_read);

		memcpy(file_content + content_size, buffer, bytes_read);
		content_size += bytes_read;
	}
	return (file_content);
}

/**
 * main - entry point for cd
 * @argc: number of args
 * @argv: list of args
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int fd = 0;
	char *home_dir = getenv("HOME"), cwd[BUFFER_SIZE];

	if(argc == 1)
	{
		chdir(home_dir);
		return (0);
	}
	if (strcmp(argv[1], ".") == 0) return (0);

	if (argc > 2)
	{
		perror("bash: cd: too many arguments\n");
		return (-1);
	}

	chdir(_getcwd());

	if(chdir(argv[1]) != 0)
	{
		printf("bash: cd: hello: No such file or directory\n");
		return (-1);
	}
	getcwd(cwd, sizeof(cwd));
	fd = open("/home/yk/Desktop/ALX/simple_shell/cwd.txt", O_WRONLY | O_CREAT);
	write(fd, cwd, sizeof(cwd) - 1);

	return (0);
}
