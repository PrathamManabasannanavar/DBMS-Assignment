#include<stdio.h>

int main(){
    FILE *fp = fopen("numbers.txt", "r");
    int no;
    while(fscanf(fp, "%d",&no) == 1){
        printf("%d ", no);
    }
    fclose(fp);
    return 0;
}