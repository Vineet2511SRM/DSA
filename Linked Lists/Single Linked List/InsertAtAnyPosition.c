#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Insert at end
struct node *add_at_end(struct node *ptr, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;   // connect old last node to new node
    return temp;        // return new last node
}

// Insert node at any position
void insertAtPosition(struct node **head, int data, int position) {
    struct node *ptr, *ptr2;
    ptr = *head;  // Start from the head node
    ptr2 = malloc(sizeof(struct node));  // Create a new node
    ptr2->data = data;
    ptr2->link = NULL;

    // Case 1: Insert at beginning
    if (position == 0) {
        ptr2->link = *head;  // new node points to old head
        *head = ptr2;        // head is updated
        return;
    }

    // Case 2: Insert at position > 0
    position--; // adjust to reach the node before target position
    while (position > 0 && ptr->link != NULL) {
        ptr = ptr->link;
        position--;
    }
    // Now ptr points to node before desired position
    ptr2->link = ptr->link;  // new node points to next node
    ptr->link = ptr2;        // previous node points to new node
}

// Print linked list
void printList(struct node *head) {
    struct node *ptr = head;
    printf("Current Linked List: ");
    while (ptr != NULL) {
        printf("%d", ptr->data);
        if (ptr->link != NULL) {
            printf(" -> ");
        }
        ptr = ptr->link;
    }
    printf(" -> NULL\n");
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *temp = head;

    temp = add_at_end(temp, 20);
    temp = add_at_end(temp, 30);
    temp = add_at_end(temp, 40);

    printf("Original List:\n");
    printList(head);

    int data = 25, position = 2;
    printf("\nInserting %d at position %d...\n", data, position);
    insertAtPosition(&head, data, position);

    printf("\nModified List:\n");
    printList(head);

    return 0;
}
