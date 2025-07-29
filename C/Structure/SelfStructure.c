#include<stdio.h>

struct mem {
    int value;
    struct mem *next; // Pointer to the next node
}mem1,mem2;

int main(){
    mem1.value = 100; // Assigning value to first node
    mem1.next = NULL; // Initializing next pointer to NULL

    mem2.value = 200; // Assigning value to second node
    mem2.next = NULL; // Initializing next pointer to NULL

    // Linking the first node to the second node
    mem1.next = &mem2;

    // Displaying the values of the linked nodes
    printf("Value of first node: %d\n", mem1.value);
    printf("Value of second node: %d\n", mem1.next->value);

    printf("%d ", mem1.next); // Address of the second node

    return 0; // Program end
}