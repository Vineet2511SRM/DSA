#include <stdio.h>
#include <stdlib.h>

// Define structure of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete the last node
struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {  // Empty list
        printf("List is already empty!\n");
        return NULL;
    }

    if (head->next == NULL) {  // Only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;  // Disconnect last node from second-last
    free(temp);               // Free memory

    return head;              // Return head
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) return newNode;  // Empty list

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// MAIN
int main() {
    struct Node* head = NULL;

    // Create list: 10 <-> 20 <-> 30
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original List:\n");
    display(head);

    // Delete last node
    head = deleteLastNode(head);

    printf("After deleting last node:\n");
    display(head);

    return 0;
}
