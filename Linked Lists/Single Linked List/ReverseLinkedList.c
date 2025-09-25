#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct node {
    int data;
    struct node *link;
};

// Function to insert a node at the end
struct node* insertAtEnd(struct node *head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL) {
        return newNode; // If list is empty, new node becomes head
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

// Function to reverse the linked list (iterative)
struct node* reverseList(struct node *head) {
    struct node *prev = NULL;     // Previous pointer
    struct node *current = head;  // Current pointer
    struct node *next = NULL;     // Next pointer

    while (current != NULL) {
        next = current->link;     // Save the next node
        current->link = prev;     // Reverse the link
        prev = current;           // Move prev one step forward
        current = next;           // Move current one step forward
    }

    // After the loop, prev will be the new head
    return prev;
}

// Driver code
int main() {
    struct node *head = NULL;

    // Create linked list: 10 -> 20 -> 30 -> 40 -> NULL
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original List: ");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
