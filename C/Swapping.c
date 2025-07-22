/*This program takes two integer input from user and do swapping
1 - > Normal Swapping
2 - > Swapping using pointer dereferencing*/

#include<stdio.h>
int main(){
    int x1,x2,temp;
    printf("Enter first integer : ");
    scanf("%d",&x1);
    printf("Enter second integer : ");
    scanf("%d",&x2);

    printf("Before swapping : x1 = %d, x2 = %d\n", x1, x2);

    //Performing normal swapping
    temp = x1; // Store the value of x1 in temp;
    x1 = x2; // Assign the value of x2 to x1;
    x2 = temp; // Assign the value of temp (original x1) to x2;

    printf("After normal swapping : x1 = %d, x2 = %d\n", x1, x2);

    //Performing swapping using pointer dereferencing
    int *ptr1 = &x1; // Pointer to x1
    int *ptr2 = &x2; // Pointer to x2

    printf("Before swapping using pointers: x1 = %d, x2 = %d\n", *ptr1, *ptr2);
    
    temp = *ptr1; // Store the value pointed by ptr1 (x1) in temp
    *ptr1 = *ptr2; // Assign the value pointed by ptr2 (x2) to the value pointed by ptr1 (x1)
    *ptr2 = temp; // Assign the value of temp (original x1) to the value pointed by ptr2 (x2)

    printf("After swapping using pointers: x1 = %d, x2 = %d\n", *ptr1, *ptr2);

    return 0;
}