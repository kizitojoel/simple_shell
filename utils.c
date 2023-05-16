#include "main.h"

/**
 * validate_path - check whether a path points to a file or not
 * @path: the string to check
 * Return: 0 if the string is a valid file path else -1
 */
int validate_path(char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) != 0)
    {
        printf("%s: command not found\n", path);
        return (-1);
    }
    if (!S_ISREG(path_stat.st_mode))
    {
        printf("%s is not a file.\n", path);
        return (-1);
    }

    return (0);
}

/**
 * execute_command - executes the passed command with the passed args
 * @args: the args to pass to the execve
 */
void execute_command(char **args)
{
    pid_t subprocess;
    int status;

    subprocess = fork();
    if (subprocess == -1)
        perror("fork failed!\n");
    else if (subprocess == 0)
    {
        printf("calling execve");
        execve(args[0], args, NULL);
        printf("Unknown command\n");
        exit(0);
    }
    else
        wait(&status);

}

/**
 * _strip - remove trailing spaces from string
 * @str: the string to strip
 */
void _strip(char *str)
{
    int length = strlen(str);

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

#define BUFFER_SIZE 1024
char *_getcwd()
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    char *file_content = NULL;
    size_t content_size = 0;

    fd = open("cwd.txt", O_RDONLY);

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        file_content = realloc(file_content, content_size + bytes_read);

        memcpy(file_content + content_size, buffer, bytes_read);
        content_size += bytes_read;
    }

    return (file_content);
}