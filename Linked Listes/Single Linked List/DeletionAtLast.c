#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to insert node at end
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL) return newNode;

    struct node* temp = head;
    while (temp->link != NULL) temp = temp->link;
    temp->link = newNode;
    return head;
}

// Function to print list
void printList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Correct deleteLastNode function
struct node* deleteLastNode(struct node* head) {
    if (head == NULL) return NULL;
    if (head->link == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->link->link != NULL) temp = temp->link;
    free(temp->link);
    temp->link = NULL;
    return head;
}

int main() {
    struct node* head = NULL;

    // Create linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original list: ");
    printList(head);

    // Delete last node
    head = deleteLastNode(head);
    printf("After deleting last node: ");
    printList(head);

    // Delete again
    head = deleteLastNode(head);
    printf("After deleting last node again: ");
    printList(head);

    // Delete all remaining nodes
    head = deleteLastNode(head);
    head = deleteLastNode(head);
    printf("After deleting all nodes: ");
    printList(head);

    return 0;
}
