// C program to create a node in a circular singly and doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct NodeSingly {
    int data;
    struct NodeSingly* next; // Pointer to the next node
};

// Function to create a node in a circular singly linked list
struct NodeSingly* createCircularSinglyNode(int data) {
    struct NodeSingly* newNode = (struct NodeSingly*)malloc(sizeof(struct NodeSingly));
    newNode->data = data;
    newNode->next = newNode; // Point to itself to make it circular
    return newNode;
}

struct NodeDoubly {
    int data;
    struct NodeDoubly* next; // Pointer to the next node
    struct NodeDoubly* prev; // Pointer to the previous node
};

// Function to create a node in a circular doubly linked list
struct NodeDoubly* createCircularDoublyNode(int data) {
    struct NodeDoubly* newNode = (struct NodeDoubly*)malloc(sizeof(struct NodeDoubly));
    newNode->data = data;
    newNode->next = newNode; // Point to itself to make it circular
    newNode->prev = newNode; // Point to itself to make it circular
    return newNode;
}

int main() {
    // Create a node in circular singly linked list
    struct NodeSingly* singlyNode = createCircularSinglyNode(1);
    printf("Circular Singly Linked List Node: %d -> %d (points to itself)\n", singlyNode->data, singlyNode->next->data);

    // Create a node in circular doubly linked list
    struct NodeDoubly* doublyNode = createCircularDoublyNode(2);
    printf("Circular Doubly Linked List Node: %d <-> %d (points to itself)\n", doublyNode->data, doublyNode->next->data);

    // Free allocated memory
    free(singlyNode);
    free(doublyNode);

    return 0;
}