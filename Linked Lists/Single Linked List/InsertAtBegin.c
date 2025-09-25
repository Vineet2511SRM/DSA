// C program to add a node at the beginning of a linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Insert node at beginning
void insertAtBegin(struct node **head, int data) {
    struct node *temp;

    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = *head; // New node points to the former head

    *head = temp; // Head now points to the new node
}

// Print linked list
void printList(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *second = malloc(sizeof(struct node));
    second->data = 20;
    second->link = NULL;

    // Link first node with second
    head->link = second;

    // Printing original list
    printf("Original list:\n");
    printList(head);

    // Inserting nodes at the beginning
    insertAtBegin(&head, 5); // &head because we need to modify the head pointer
    insertAtBegin(&head, 1);
    insertAtBegin(&head, 0);

    // Printing modified list
    printf("Modified list after inserting at beginning:\n");
    printList(head);

    return 0;
}