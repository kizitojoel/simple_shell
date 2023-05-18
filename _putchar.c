#include "unistd.h"


/**
 * _putchar - prints a character
 * @c: the character to be printed
 * Return: number of bytes written
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
