#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Utility: create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Utility: insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) return newNode; // empty list

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Utility: count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function: delete at position
struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    int n = countNodes(head);
    if (pos < 1 || pos > n) {
        printf("Invalid position! Choose between 1 and %d\n", n);
        return head;
    }

    // Case 1: delete first node
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        return head;
    }

    // Case 2: delete last node
    if (pos == n) {
        struct Node* temp = head;
        while (temp->next != NULL) temp = temp->next; // last node
        temp->prev->next = NULL;
        free(temp);
        return head;
    }

    // Case 3: delete middle node
    struct Node* temp = head;
    for (int i = 1; i < pos; i++) temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return head;
}

// Utility: display
void display(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    struct Node* head = NULL;
    int n, data, pos;

    // Create list
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("\nOriginal List:\n");
    display(head);

    // Delete at given position
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    head = deleteAtPosition(head, pos);

    printf("\nAfter Deletion:\n");
    display(head);

    return 0;
}
