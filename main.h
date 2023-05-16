#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include<sys/wait.h>

int main(void);
void execute_command(char **args);
int validate_path(char *path);
int _strlen(const char *c);
void _strip(char *str);
char *_getcwd();
#endif
