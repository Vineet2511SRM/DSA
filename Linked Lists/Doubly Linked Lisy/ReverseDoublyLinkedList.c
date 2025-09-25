#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Display
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Reverse DLL using two-pointer approach
struct Node* reverseDLL(struct Node* head) {
    if (!head) return NULL;

    struct Node* ptr1 = head; 
    struct Node* ptr2 = ptr1->next; // second node

    ptr1->next = NULL;       // will become last node
    ptr1->prev = ptr2; // new prev of first node

    while (ptr2 != NULL) {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;

        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }

    head = ptr1;
    return head;
}

// Main
int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original List:\n");
    display(head);

    head = reverseDLL(head);

    printf("\nReversed List:\n");
    display(head);

    return 0;
}
