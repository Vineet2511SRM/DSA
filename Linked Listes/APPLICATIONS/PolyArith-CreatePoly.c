// c program to create a polynomial
#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head,float co, int ex){
    struct node* temp;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = co;
    newNode->expo = ex;
    newNode->link = NULL;

    // If there is no head or new node has greater exponent than head
    if(head == NULL || ex > head->expo){
        newNode->link = head;
        head = newNode;
    } else {
        temp = head;
        // Traverse to find the correct position to insert
        while(temp->link != NULL && temp->link->expo >= ex){
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
    return head;
}

struct node* createPoly(struct node* head) {
    int n, i, ex;
    float co;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%f %d", &co, &ex);
        head = insert(head, co, ex);
    }
    return head;
}

void displayPoly(struct node* head) {
    struct node* temp = head;
    if (temp == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%.1fx^%d", temp->coeff, temp->expo);
        temp = temp->link;
        if (temp != NULL) {
            printf(" + ");
        }
        else {
            printf("\n");
        }
    }
}

int main() {
    struct node* poly = NULL;
    poly = createPoly(poly);
    printf("The polynomial is: ");
    displayPoly(poly);
    return 0;
}