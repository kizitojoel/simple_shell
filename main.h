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
#include <limits.h>

/* External environment variable*/
extern char **environ;

void _execute_command(char **args, char **env);
void execute_command(char **args, char **env);
int _validate_path(char *path);
int _strlen(const char *c);
void _strip(char *str);
char *_getcwd();
int _putchar(char c);
char *_strcat(char *dest, char *src);
int _puts(char *str);

/* Environment variables*/
char **_copyenv(void);

#endif
