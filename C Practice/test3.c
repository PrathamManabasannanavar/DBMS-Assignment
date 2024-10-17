#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main()
{
    char buffer[100];
    int fd = open("hello.txt", O_RDONLY);
    int bytes_read = read(fd, buffer, sizeof(buffer)); //this is the system call
    if (bytes_read < 0)
    {
        perror("file read error");
        return 1;
    }
    printf("bytes read: %d\n", bytes_read);
    printf("%s", buffer);
    close(fd);
    return 0;
}