// C program to read and print student information using array of structures

#include<stdio.h>

struct Student {
    char name[20];
    int roll_no;
    float cpi;
};

int main(){
    int i,n; 
    printf("Enter the number of records you want to store : ");
    scanf("%d", &n);

    struct Student sarr[n]; // Declare an array of structures
    for(i = 0; i < n; i++){
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", sarr[i].name); // Input name
        printf("Enter the roll number of student %d: ", i + 1);
        scanf("%d", &sarr[i].roll_no); // Input roll number
        printf("Enter the CPI of student %d: ", i + 1);
        scanf("%f", &sarr[i].cpi); // Input CPI
    }

    // Displaying the records
    printf("\n--- Student Records ---\n");
    printf("\n\tName\tRoll No\tCPI\t\n");
    for (i = 0; i < n; i++) {
        printf("\t%s\t%d\t%.2f\n", sarr[i].name, sarr[i].roll_no, sarr[i].cpi);
    }

    printf("\n--- End of Records ---\n");

    return 0;
}