//This pgm doesn't work on windows only on --> Unix based systems
//include windows.h -> header file
#include<stdio.h>
#include<unistd.h>

int main(){
    printf("main started executing");
    pid_t pid = fork();
    if(pid == 0){
        printf("child");
    }else{
        printf("parent");
    }
    return 0;
}