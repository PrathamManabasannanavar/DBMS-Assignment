#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>


int main()
{
    int fd = open("hello1.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    const char *text = "Hello World";
    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written < 0)
    {
        perror("write");
        return 1;
    }
    close(fd);
    return 0;
}