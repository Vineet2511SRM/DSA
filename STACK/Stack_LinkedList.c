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

// Peek operation
void peek(struct stack *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
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
    int choice, val;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
