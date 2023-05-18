#include "main.h"

/**
 * _strlen - counts the characters in a string
 * @c: the string to count
 *
 * Return: the number of characters in the string
 */
int _strlen(const char *c)
{
	int length = 0;

	if (c == NULL)
		return (length);
	while (*c != '\0')
	{
		length++;
		c++;
	}
	return (length);
}

