#include "main.h"

/**
 * main - creates a directory
 * @argc: number of args
 * @argv: a list of args
 * Return: Always 0
 */
int main(int __attribute__ ((unused)) argc, char *argv[])
{
	char *path = search_command(argv[0]);

	argv[0] = path;

	chdir(_getcwd());
	execve(path,argv,environ);

	return (0);
}
