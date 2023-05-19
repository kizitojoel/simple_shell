#include "main.h"

/**
 * main - displays a line of text
 * @argc: number of args
 * @argv: list of args
 * Return: 0 if success else -1
 */
int main(int argc, char *argv[])
{
	size_t  j;
	int i;
	char *word;

	for (i = 1; i < argc; i++)
	{
		word = argv[i];
		for (j = 0; j < strlen(word); j++)
		{
			if(word[j] != '\'' && word[j] != '\"')
				_putchar(word[j]);
		}
		if (i < argc - 1)
			printf(" ");
	}
	_putchar('\n');
	return (0);
}
