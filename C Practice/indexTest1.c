#include<stdio.h>

int main()
{
    int arr[] = {21, 5, 32};
    int *ptr = arr+2;
    printf("%u", ptr);
    // printf("%d - %u\n", *ptr, ptr--);
    printf("%d\n",*ptr--);
    printf("%d - %u\n", *ptr, ptr);

    return 0;
}
