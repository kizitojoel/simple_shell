#include "main.h"

/**
 * _strip - remove trailing spaces from string
 * @str: the string to strip
 */
void _strip(char *str)
{
	int length = _strlen(str);

	if (length > 0)
	{
		while (length > 0 && (str[length - 1] == ' ' ||
							  str[length - 1] == '\n' || str[length - 1] == '\r'))
		{
			str[length - 1] = '\0';
			length--;
		}
	}
}
