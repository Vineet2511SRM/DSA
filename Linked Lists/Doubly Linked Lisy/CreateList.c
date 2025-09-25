// C program to create an entire doubly linked list
// Add first node usinf addToEmpty function
// Then add more nodes using insertAtEnd function

#include <stdio.h>
#include <stdlib.h>

// Define structure of a Node
struct Node {
    int data;
    struct Node* next; // Pointer to next node
    struct Node* prev; // Pointer to previous node
};

// Function to insert a node in an empty doubly linked list
struct Node* insertInEmpty(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return head;
}

// Function to insert a node at the end of a doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next; // Move to next node
    }

    temp->next = newNode; // Link last node to new node
    newNode->prev = temp; // Link new node back to last node

    return head;
}

// Function to display the doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// function to create list
struct Node* createList(struct Node* head) {
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) return head;

    printf("Enter the data for node 1: ");
    scanf("%d", &data);
    head = insertInEmpty(head, data);

    for (i = 2; i <= n; i++) {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    return head;
}

int main() {
    struct Node* head = NULL; // Initialize head to NULL
    // Create the list
    head = createList(head);
    printf("After creating the list:\n");
    display(head);

    return 0;
}

