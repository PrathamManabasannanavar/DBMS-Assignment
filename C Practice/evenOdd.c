#include<stdio.h>

int main(){
    FILE *fp = fopen("numbers.txt", "r");
    int no;
    while((no = fgetc(fp)) != EOF){
        if(no == ' ') continue;
        no -= '0';
        printf("%d ", no);
    }
    fclose(fp);
    return 0;
}