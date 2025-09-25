#include <stdio.h>
#include <stdlib.h>

// Node structure
struct stack {
    int data;
    struct stack *next;
};

// Push operation
struct stack* push(struct stack *top, int val) {
    struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return top;
    }

    ptr->data = val;

    // If stack is empty, new node becomes top
    if (top == NULL) {
        ptr->next = NULL;
        top = ptr;
    } 
    else {
        ptr->next = top;
        top = ptr;
    }
    return top;
}

// Display stack (to check push result)
void display(struct stack *top) {
    struct stack *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct stack *top = NULL;

    // Push elements
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    display(top);

    return 0;
}
