// C program to delete a node at any particular position in a singly linked list
#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct node {
    int data;
    struct node *link;
};

// Function to insert a node at the end of the list
struct node* insertAtEnd(struct node *head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL) {
        return newNode; // First node becomes head
    }

    struct node *temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    return head;
}

// Function to print the linked list
void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Function to delete a node at a given position
void del_pos(struct node **head, int pos) {
    if (*head == NULL) {  // If list is empty
        printf("List is already empty.\n");
        return;
    }

    struct node *current = *head;
    struct node *previous = NULL;

    // Case 1: Delete the head (position = 1)
    if (pos == 1) {
        *head = current->link; // Move head to next node
        free(current);         // Free old head
        return;
    }

    // Case 2: Delete at position > 1
    while (pos > 1 && current != NULL) {
        previous = current;
        current = current->link;
        pos--;
    }

    // If position was invalid (greater than list length)
    if (current == NULL) {
        printf("Position out of range.\n");
        return;
    }

    // Disconnect current node and free it
    previous->link = current->link;
    free(current);
}

int main() {
    int position;
    struct node* head = NULL;

    // Create a sample linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original list: ");
    printList(head);

    // Ask user for position
    printf("Enter position at which you want to delete node: ");
    scanf("%d", &position);

    // Delete node at given position
    del_pos(&head, position);

    // Print updated list
    printf("Updated list: ");
    printList(head);

    return 0;
}
