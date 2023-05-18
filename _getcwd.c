#include "main.h"

#define BUFFER_SIZE 4096

/**
 * _getcwd - get working directory
 * Return: The current directory path
 */
char *_getcwd()
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    char *file_content = NULL, *cwd_file_name = "/cwd.txt";
    size_t content_size = 0;
    char *cwd_file_path = _strcat(getcwd(buffer, sizeof(buffer)), cwd_file_name);

    fd = open(cwd_file_path, O_RDONLY);

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        file_content = realloc(file_content, content_size + bytes_read);

        memcpy(file_content + content_size, buffer, bytes_read);
        content_size += bytes_read;
    }
    return (file_content);
}
