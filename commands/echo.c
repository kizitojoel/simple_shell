#include "main.h"

/**
 * main - displays a line of text
 * @argc: number of args
 * @argv: list of args
 * Return: 0 if success else -1
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
	{
		printf("%s", argv[i]);
		if (i < argc - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}
