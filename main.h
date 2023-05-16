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
void _execute_command(char **args);
int _validate_path(char *path);
int _strlen(const char *c);
void _strip(char *str);
char *_getcwd();
char *_getcwd();
char *_strcat(char *dest, char *src);

#endif
