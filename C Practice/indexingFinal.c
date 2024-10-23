//A simple C pgm to read and print the details of the employees
#include<stdio.h>
#include<stdlib.h>

#define SIZE 30
#define ECOUNT 10

typedef struct Employee{
    int empID;
    char name[SIZE];
    float salary;
}Employee;

void readEmployeeDetails(Employee *e, int n){
    for(int i=0; i<n; i++){
        printf("Enter the employee %d details\n", i+1);
        printf("Enter the employee id\n");
        scanf("%d",&e[i].empID);
         printf("Enter the employee name\n");
        scanf("%s",&e[i].name);
        printf("Enter the employee salary\n\n");
        scanf("%s",&e[i].salary);
    }
}

void printEmployeeDetails(Employee *e, int n){
    for(int i=0; i<n; i++){
        printf("EMPID : %d\n",e[i].empID);
        printf("EMP Name : %d\n",e[i].name);
        printf("EMP Salary : %d\n\n",e[i].salary);
    }
}

int main(){
    Employee e[ECOUNT];
    int n;
    printf("Enter the no of employees\n");
    scanf("%d",&n);

    if(n > ECOUNT){
        printf("max employees = %d\n", ECOUNT);
        exit(0);
    }

    readEmployeeDetails(e, n);
    printEmployeeDetails(e, n);
    return 0;
}