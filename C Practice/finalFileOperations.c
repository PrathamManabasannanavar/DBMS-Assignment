//A simple C program to showcase the System calls in Unix based OS systems
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

char* readFile(char *str);
void writeFile(char *str);
void appendFile(char *str);

int main(){
    int choice;
    char str[SIZE];
    printf("Enter (1-read) (2-write) (3-append) file\n");
    printf("Enter yoour choice\n");
    scanf("%d",&choice);
    getchar();
    switch (choice)
    {
    case 1:
        printf("Enter the file name to read\n");
        scanf("%s",str);
        getchar(); //clr the I/P stream
        printf("The contents of the file are:\n%s\n",readFile(str));
        break;
    case 2:
        printf("Enter the file name to write\n");
        scanf("%s",str);
        getchar();
        writeFile(str);
        break;
    case 3:
        printf("Enter the file name to appended\n");
        scanf("%s",str);
        getchar();
        appendFile(str);
        break;
    default:
        break;
    }
    return 0;
}

void writeFile(char *filename){
    fflush(stdin);
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd < 0){
        perror("Error occured while opning the file\n");
        close(fd);
        return;
    }
    char str[SIZE];
    printf("Enter the string to be writen\n");
    fgets(str, SIZE, stdin);
    write(fd, str, strlen(str));
    close(fd);
}

char *readFile(char *filename){
    char *str = (char *)malloc(SIZE*sizeof(char));
    int fd = open(filename, O_RDONLY);
    if(fd < 0){
        perror("Can't open this file\n");
        free(str);
        close(fd);
        return NULL;
    }
    int bytesRead = read(fd, str, SIZE-1);
    str[bytesRead] = '\0';
    close(fd);
    return str;
}

void appendFile(char *filename){
int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
  if(fd < 0){
        perror("Can't append to the file\n");
        close(fd);
        return;
    }
    char str[SIZE];
    fflush(stdin);
    printf("Enter the String to appended\n");
    fgets(str, SIZE, stdin);
    write(fd, str, strlen(str));
}
