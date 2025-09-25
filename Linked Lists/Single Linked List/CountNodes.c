#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *link;
};

// Function to count nodes
void count_nodes(struct node *head) {
    int count = 0;
    struct node *ptr = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    while (ptr != NULL) {
        count++;
        ptr = ptr->link; // Move to next node
    }
    printf("Number of nodes in the linked list: %d\n", count);
}

// Function to print linked list
// Function to print the linked list (Traversal)
void print(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return; // Nothing to traverse
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link; // move to next node
    }
    printf("NULL\n");
}

int main() {
    int n, i, val;
    struct node *head = NULL, *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Linked list will be empty!\n");
        return 0;
    }

    // Create head node
    printf("Enter data for node 1: ");
    scanf("%d", &val);
    head = (struct node*)malloc(sizeof(struct node));
    head->data = val;
    head->link = NULL;
    temp = head;

    // Create remaining nodes using loop
    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->link = NULL;

        temp->link = newNode; // link last node to new node
        temp = newNode;       // move temp forward
    }

    // Count nodes
    count_nodes(head);

    // Printing the link list
    print(head);

    return 0;
}
