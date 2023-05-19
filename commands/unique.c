#include "main.h"

int main(int argc, char *argv[])
{

	printf("executing unique");

	if(argc > 1)
	{
		printf(" with args: ");
		printf("%s", argv[0]);
	}
	printf("\n");

	return (0);
}
