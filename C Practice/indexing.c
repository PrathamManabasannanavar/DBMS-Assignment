#include <stdio.h>
#define SIZE 30

void readArray(int *arr, int n){
    printf("Enter the elements of the array");
    for(int i = 0; i < n; i++){
        printf("Enter the element no %d\n", i+1);
        scanf("%d", arr+i);
    }
}

void displayArray(int *arr, int n){
    printf("The elements of the arrya are:\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int deleteEleInArray(int *arr, int *n, int key){
    int i=0;
    for(i=0; i<*n; i++){
        if(key == arr[i]){
            break;
        }
    }
    if(i == *n){
        return 0;
    }
    while(i < *n-1){
        arr[i] = arr[i+1];
        i++;
    }
    (*n)--;
    return 1;
}

int main()
{
    int arr[SIZE], n;
    printf("Enter the no of elements in the array\n");
    scanf("%d", &n);
    readArray(arr, n);
    displayArray(arr, n);
    int status  = deleteEleInArray(arr, &n, 5);
    if(status){
        printf("deleted\n");
    }else{
        printf("not deleted\n");
    }
    displayArray(arr, n);
    return 0;
}