// c program to delete a node at the beginning of a doubly linked list
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

// Function to delete the first node
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {  // Empty list
        printf("List is already empty!\n");
        return NULL;
    }

    if (head->next == NULL) {  // Only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;  // Store old head
    head = head->next;         // Move head to next node
    head->prev = NULL;         // Update new head's prev
    free(temp);                // Free old head

    return head;               // Return new head
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) return newNode;  // Empty list

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;

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

    // Delete first node
    head = deleteFirstNode(head);

    printf("After deleting first node:\n");
    display(head);

    return 0;
}
