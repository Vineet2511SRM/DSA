// Simple C program for Traversing a Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list (Traversal)
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return; // Nothing to traverse
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; // move to next node
    }
    printf("NULL\n");
}

int main() {
    // Creating nodes
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));

    // Assigning data
    head->data = 10; head->next = second;
    second->data = 20; second->next = third;
    third->data = 30; third->next = NULL;

    // Traversing
    traverse(head);

    return 0;
}
