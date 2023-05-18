#include "main.h"

/**
 * main - prints the current working directory
 * @argc: number of args
 * @argv: list of args
 * Return: always 0
 */
int main(int __attribute__ ((unused)) argc, char __attribute__ ((unused)) *argv[])
{
    printf("%s\n", _getcwd());

    return (0);
}