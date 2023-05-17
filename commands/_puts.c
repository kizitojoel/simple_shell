#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: the string poitner
 *
 * Return: the number of characters printed
 */
int _puts(char *str)
{
	int count = 0;

	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}
