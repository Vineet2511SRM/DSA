#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to delete the first node of the linked list
struct node* deleteFirstNode(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    struct node *temp = head; // Store the current head
    head = head->link;        // Move head to the next node
    free(temp);               // Free the old head
    return head;              // Return the new head
}

// Function to insert a node at the end
struct node* insertAtEnd(struct node *head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL) {
        return newNode;
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

int main() {
    struct node *head = NULL;

    // Create linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original List: ");
    printList(head);

    // Delete first node
    head = deleteFirstNode(head);
    printf("After deleting first node: ");
    printList(head);

    // Delete again
    head = deleteFirstNode(head);
    printf("After deleting first node again: ");
    printList(head);

    // Free remaining nodes
    while (head != NULL) {
        head = deleteFirstNode(head);
    }

    return 0;
}
