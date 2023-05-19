#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>

extern char **environ;

char *_strcat(char *dest, char *src);
char *_getcwd();
int _putchar(char c);
int _puts(char *str);

#endif
