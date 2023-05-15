#include "main.h"

/**
 * main - entry point for cd
 * @argc: number of args
 * @argv: list of args
 * Return: always 0
 */
int main(int argc, char *argv[])
{
    char *home_dir = getenv("HOME");

    if(argc == 1)
    {
        chdir(home_dir);
        return (0);
    }
    if (strcmp(argv[1], ".") == 0) return (0);

    if (argc > 2)
    {
        perror("bash: cd: too many arguments\n");
        return (-1);
    }
    if(chdir(argv[1]) != 0)
    {
        printf("bash: cd: hello: No such file or directory\n");
        return (-1);
    }
    return (0);
}
