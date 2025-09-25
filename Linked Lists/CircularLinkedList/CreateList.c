#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to add first node (when list is empty)
struct node* addAtEmpty(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode; // points to itself
    return newNode;          // tail = newNode
}

// Function to add node at end
struct node* addAtEnd(struct node* tail, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    newNode->next = tail->next; // newNode → head
    tail->next = newNode;       // old tail → newNode
    tail = newNode;             // update tail
    return tail;
}

// Function to display circular linked list
void display(struct node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* p = tail->next; // head
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

// Function to create a circular linked list
struct node* createList(struct node* tail) {
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Empty list created!\n");
        return NULL;
    }

    // First node
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    tail = addAtEmpty(data);

    // Remaining nodes
    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }

    return tail;
}

// MAIN
int main() {
    struct node* tail = NULL;  
    tail = createList(tail);    // Pass tail to function

    printf("Circular Linked List: ");
    display(tail);

    return 0;
}
