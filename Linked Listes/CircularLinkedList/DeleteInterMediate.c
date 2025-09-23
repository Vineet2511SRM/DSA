
// Circular Singly Linked List - Delete at Any Position
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

// Function to count nodes (for safety)
int countNodes(struct node *tail) {
    if (tail == NULL) return 0;
    int count = 0;
    struct node *temp = tail->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;
}

// Function to delete node at any position
struct node* delAnyPos(struct node* tail, int pos) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    int n = countNodes(tail);
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return tail;
    }

    if (tail->next == tail) { // Only one node
        free(tail);
        return NULL;
    }

    struct node *temp1 = tail->next, *temp2;

    // Case 1: Delete first node
    if (pos == 1) {
        tail->next = temp1->next; // move head
        free(temp1);
        return tail;
    }

    // Traverse to (pos-1)th node
    for (int i = 1; i < pos - 1; i++) {
        temp1 = temp1->next;
    }

    temp2 = temp1->next;        // node to delete
    temp1->next = temp2->next;  // bypass node

    // Case 2: If deleting last node
    if (temp2 == tail)
        tail = temp1;

    free(temp2);
    return tail;
}

// MAIN
int main() {
    struct node* tail = NULL;  
    tail = createList(tail);    // Create list

    printf("\nList before deletion: ");
    display(tail);

    int pos;
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    tail = delAnyPos(tail, pos);

    printf("List after deletion: ");
    display(tail);

    return 0;
}
