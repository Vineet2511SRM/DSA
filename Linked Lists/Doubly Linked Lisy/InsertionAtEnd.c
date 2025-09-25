#include <stdio.h>
#include <stdlib.h>

// Define structure of a Node
struct Node {
    int data;
    struct Node* next; // Pointer to next node
    struct Node* prev; // Pointer to previous node
};

// Function to insert a node in an empty doubly linked list
struct Node* insertInEmpty(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return head;
}

// Function to insert a node at the beginning of a doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    return head;
}

// Function to insert a node at the end of a doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to display the doubly linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate all insertions
int main() {
    struct Node* head = NULL;

    // Insert in empty list
    head = insertInEmpty(head, 10);
    printf("After inserting 10 in empty list:\n");
    display(head);

    // Insert at beginning
    head = insertAtBeginning(head, 5);
    printf("After inserting 5 at beginning:\n");
    display(head);

    // Insert at end
    head = insertAtEnd(head, 20);
    printf("After inserting 20 at end:\n");
    display(head);

    head = insertAtEnd(head, 30);
    printf("After inserting 30 at end:\n");
    display(head);

    return 0;
}
