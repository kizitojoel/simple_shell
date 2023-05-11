#include "stdio.h"

int main(int argc, char *argv[])
{
	int i = 0;

	printf("Executing ls....with args: ");

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			printf("%s ", argv[i]);
		}

	}
	return (0);
}