#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Display function
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at end (helper function for building list)
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at a specific position
struct Node* insertAtPosition(struct Node* head, int data, int pos, int flag) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1 && flag == 0) { // Insert at beginning
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    struct Node* temp = head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    if (flag == 1) { // Insert AFTER
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    } else { // Insert BEFORE
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    return head;
}

int main() {
    struct Node* head = NULL;

    // Build initial list using insertAtEnd
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original List: ");
    display(head);

    // Insert 15 BEFORE position 2
    head = insertAtPosition(head, 15, 2, 0);
    printf("After inserting 15 BEFORE pos 2: ");
    display(head);

    // Insert 25 AFTER position 3
    head = insertAtPosition(head, 25, 3, 1);
    printf("After inserting 25 AFTER pos 3: ");
    display(head);

    // Insert 5 BEFORE position 1 (at beginning)
    head = insertAtPosition(head, 5, 1, 0);
    printf("After inserting 5 BEFORE pos 1: ");
    display(head);

    return 0;
}
