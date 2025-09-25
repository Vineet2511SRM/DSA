#include <stdio.h>
#include <stdlib.h>
#define MAX 100   // maximum size of stack

int stack[MAX];
int top = -1;

// Push operation
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack OVERFLOW\n");
        return;
    }
    top++;
    stack[top] = val;
    printf("Pushed: %d\n", val);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack UNDERFLOW\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- STACK MENU (Array Implementation) ---\n");
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
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
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
