#include "../main.h"

/**
 * main - prints the environment variables
 *
 * Description: the extern global variable defined in main.h enables env
 * Return: 0 if successful
 */
int main(void)
{
	int i = 0;

	if (environ == NULL)
	{
		printf("No environment variables found");
		return (1);
	}
	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
	return (0);
}
