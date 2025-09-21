#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add node at end
struct node* addEnd(struct node* tail, int data) {
    struct node* newNode = createNode(data);

    if (tail == NULL) {
        // First node creation
        newNode->next = newNode;
        return newNode;  // tail = newNode
    }

    newNode->next = tail->next; // link newNode to head
    tail->next = newNode;       // link old tail to newNode
    tail = newNode;             // make newNode the new tail
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

// Insert after a given position
struct node* addAfterPos(struct node* tail, int data, int pos) {
    if (tail == NULL) {
        printf("List empty, cannot insert!\n");
        return NULL;
    }

    struct node* p = tail->next; // start from head
    while (pos > 1) {
        p = p->next;
        pos--;
        if (p == tail->next) { // if we come full circle
            printf("Position out of range!\n");
            return tail;
        }
    }

    struct node* newNode = createNode(data);
    newNode->next = p->next;
    p->next = newNode;

    if (p == tail) {
        // Inserted after last node → update tail
        tail = newNode;  // here is tail=newNode difference
    }

    return tail;
}

// MAIN
int main() {
    struct node* tail = NULL;

    // Create circular list
    tail = addEnd(tail, 10);
    tail = addEnd(tail, 20);
    tail = addEnd(tail, 30);
    tail = addEnd(tail, 40);

    printf("Original list: ");
    display(tail);

    // Insert 25 after position 2
    tail = addAfterPos(tail, 25, 2);
    printf("After inserting 25 after pos 2: ");
    display(tail);

    // Insert 50 after last node
    tail = addAfterPos(tail, 50, 5);  // after 40
    printf("After inserting 50 after last node: ");
    display(tail);

    return 0;
}
