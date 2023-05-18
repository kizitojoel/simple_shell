#include "main.h"

/**
 * main - create empty file(s) with the passed name(s)
 * @argc: number of args
 * @argv: list of args
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
	{
	printf("touch: missing file operand");
	return (-1);
	}
	chdir(_getcwd());
	for (i = 0; i < argc; i++)
	{
		open(argv[i], O_CREAT | O_RDWR | O_TRUNC);
	}

	return (0);

}
