#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Display list forward
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Search element
int search(struct Node* head, int key) {
    int pos = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Doubly Linked List: ");
    display(head);

    printf("Enter element to search: ");
    scanf("%d", &data);
    int pos = search(head, data);
    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", pos);

    return 0;
}
