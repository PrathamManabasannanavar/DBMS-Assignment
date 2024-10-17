#include<stdio.h>
#include<string.h>

int main(){
    int no;
    char buffer[8];
    FILE *fp = fopen("hello.txt", "r");
    // fscanf(fp, "%d",&no);

    fgets(buffer, sizeof(buffer), fp);
    int i =0;
    // while(i < 34 && !feof(fp))
    //     printf("%c",(char)buffer[i++]);
    printf("%s",buffer);
    printf("%d", strlen(buffer));
    // printf("%d", no);
}