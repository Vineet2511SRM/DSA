// Count number of elements in Circular Linked List
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

// Function to count number of elements in list
int countNodes(struct node *tail) {
    if (tail == NULL) return 0;  // empty list

    int count = 0;
    struct node *temp = tail->next;  // head

    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);

    return count;
}

// MAIN
int main() {
    struct node* tail = NULL;

    // Create a circular linked list with 5 nodes
    tail = addAtEmpty(10);
    tail = addAtEnd(tail, 20);
    tail = addAtEnd(tail, 30);
    tail = addAtEnd(tail, 40);
    tail = addAtEnd(tail, 50);

    printf("Circular Linked List: ");
    display(tail);

    int total = countNodes(tail);
    printf("Number of elements in the list = %d\n", total);

    return 0;
}
