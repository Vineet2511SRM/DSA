#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Add first node
struct Node* addAtEmpty(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

// Add at end
struct Node* addAtEnd(struct Node* tail, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    return tail;
}

// Display
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Search element
int search(struct Node* tail, int key) {
    if (tail == NULL) return -1;

    struct Node* temp = tail->next;
    int pos = 1;

    do {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != tail->next);

    return -1;
}

int main() {
    struct Node* tail = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter data for node 1: ");
        scanf("%d", &data);
        tail = addAtEmpty(data);

        for (int i = 2; i <= n; i++) {
            printf("Enter data for node %d: ", i);
            scanf("%d", &data);
            tail = addAtEnd(tail, data);
        }
    }

    printf("Circular Singly Linked List: ");
    display(tail);

    printf("Enter element to search: ");
    scanf("%d", &data);
    int pos = search(tail, data);
    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", pos);

    return 0;
}
