#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push into stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Reverse array using stack
void reverseArray(int arr[], int n) {
    // Step 1: Push all elements of array into stack
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }

    // Step 2: Pop from stack and overwrite array
    for (int i = 0; i < n; i++) {
        arr[i] = pop();
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, n);

    printf("\nReversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
