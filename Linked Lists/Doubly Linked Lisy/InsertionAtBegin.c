// C program to insert a node at beginning of a doubly linked list
#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

struct Node* insertInEmpty(struct Node* head, int data) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; // Assign data to the new node
    newNode->next = NULL; // Since it's the only node, next is NULL
    newNode->prev = NULL; // Since it's the only node, prev is NULL
    head = newNode; // Update head to point to the new node
    return head; // Return the updated head
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; // Assign data to the new node
    newNode->next = head; // New node points to the current head
    newNode->prev = NULL; // New node will be the first node, so prev is NULL

    if (head != NULL) {
        head->prev = newNode; // Update previous head's prev to new node
    }

    head = newNode; // Update head to point to the new node
    return head; // Return the updated head
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize head to NULL

    head = insertInEmpty(head, 10); // Insert a node in the empty list
    display(head); // Display the list

    head = insertAtBeginning(head, 20); // Insert a node at the beginning
    display(head); // Display the list

    head = insertAtBeginning(head, 30); // Insert another node at the beginning
    display(head); // Display the list

    return 0;
}