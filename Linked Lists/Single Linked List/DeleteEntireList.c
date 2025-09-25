#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
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

// Function to delete the entire linked list
struct node *del_list(struct node *head) {
    struct node *temp = head;

    // Traverse and free each node
    while (temp != NULL) {
        temp = temp->link;   // move temp ahead
        free(head);          // free current head
        head = temp;         // update head
    }

    return head;
}

// Driver code
int main() {
    struct node *head = NULL;

    // Create linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original List: ");
    printList(head);

    // Delete entire list
    head = del_list(head);

    if(head==NULL)
        printf("Linked list deleted successfully!! \n");

    // Try printing after deletion
    printList(head);

    return 0;
}
