#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Insert node at end
void insertAtEnd(struct node **head, int data) {
    struct node *ptr, *temp;

    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        ptr = *head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

// Print linked list
void printList(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;

    insertAtEnd(&head, 10); //&head because we need to modify the head pointer
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printList(head);
    return 0;
}
