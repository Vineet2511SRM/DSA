// Simple c program to create a node in a Linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link; // Pointer to the next node
};

int main() {
    printf("Creating a simple linked list with 3 nodes (METHOD-1)\n");
    struct node *head; // head is a pointer to the first node
    head = NULL; // Initializing the head to NULL
    struct node *second;
    struct node *third;

    // Allocating memory for nodes in the linked list in heap
    head = (struct node*)malloc(sizeof(struct node)); // can be done without casting also
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Linking first and second nodes
    head->data = 1; // Assigning data in first node
    head->link = second; // Linking first node with second

    // Linking second and third nodes
    second->data = 2; // Assigning data in second node
    second->link = third; // Linking second node with third

    // Terminating the list at the third node
    third->data = 3; // Assigning data in third node
    third->link = NULL; // Ending the list at the third node

    // Printing the linked list(Traversal)
    struct node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->link;
    }
    printf("NULL\n");

    printf("Creating a simple linked list (METHOD-2)\n");
    struct node *head2 = malloc(sizeof(struct node));
    head2->data = 1;
    head2->link = NULL; 

    struct node *current2 = malloc(sizeof(struct node));
    current2->data = 2;
    current2->link = NULL;
    head2->link = current2; // Linking first and second nodes

    current2 = malloc(sizeof(struct node));
    current2->data = 3;
    current2->link = NULL; // Terminating the list at the third node
    head2->link->link = current2; // Linking second and third nodes

    // Printing the second linked list
    current2 = head2;
    while (current2 != NULL) {
        printf("%d->", current2->data);
        current2 = current2->link;
    }
    printf("NULL\n");

    printf("Difference between METHOD-1 and METHOD-2:\n");
    printf("In METHOD-1, we create and link all nodes explicitly, while in METHOD-2, we create and link nodes in a more compact way.\n");

    return 0;
}