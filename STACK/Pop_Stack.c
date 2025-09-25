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
    ptr->next = top;   // always push at top
    top = ptr;

    printf("Pushed: %d\n", val);
    return top;
}

// Pop operation
struct stack* pop(struct stack* top) {
    if (top == NULL) {
        printf("Stack UNDERFLOW\n");
        return top;
    }

    struct stack* ptr = top;
    printf("Popped: %d\n", ptr->data);

    top = top->next;
    free(ptr);
    return top;
}

// Display stack
void display(struct stack *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    struct stack *temp = top;
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

    // Pop element
    top = pop(top);
    display(top);

    // Pop again
    top = pop(top);
    display(top);

    return 0;
}
