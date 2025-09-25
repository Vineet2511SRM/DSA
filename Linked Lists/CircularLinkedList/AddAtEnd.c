// C program to insert at beginning and end in a circular singly linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next; // Pointer to the next node
};

// Function to create a circular node
struct Node* createCircularNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself
    return newNode;
}

// Function to add a node at the beginning of circular singly linked list
struct Node* addAtBeginning(struct Node* tail, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (tail == NULL) {
        // Empty list → new node is both head and tail
        newNode->next = newNode; // Point to itself
        return newNode;
    } else {
        // Insert after tail but before head
        newNode->next = tail->next; // new node → old head
        tail->next = newNode;       // tail → new node (new head)
        return tail; // Tail remains same
    }
}

// Function to add a node at the end of circular singly linked list
struct Node* addAtEnd(struct Node* tail, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (tail == NULL) {
        // Empty list → return newNode as tail
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = tail->next; // new node points to head
    tail->next = newNode;       // old tail points to new node
    tail = newNode;             // new node becomes new tail

    return tail;
}

// Function to display circular linked list
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = tail->next; // Start from head
    printf("Circular Linked List: ");

    // Traverse until we reach back to head
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("(back to head)\n");
}

// Main function
int main() {
    struct Node* tail = NULL;

    // Insert at end
    tail = addAtEnd(tail, 10);
    tail = addAtEnd(tail, 20);
    tail = addAtEnd(tail, 30);

    printf("After inserting at end:\n");
    display(tail);

    // Insert at beginning
    tail = addAtBeginning(tail, 5);
    tail = addAtBeginning(tail, 1);

    printf("\nAfter inserting at beginning:\n");
    display(tail);

    return 0;
}
