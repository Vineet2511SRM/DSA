// C program to add two polynomials
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

void addPoly(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    struct node* p1 = poly1;
    struct node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            result = insert(result, p1->coeff, p1->expo);
            p1 = p1->link;
        } else if (p1->expo < p2->expo) {
            result = insert(result, p2->coeff, p2->expo);
            p2 = p2->link;
        } else {
            float sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) { // Only insert if the coefficient is not zero
                result = insert(result, sumCoeff, p1->expo);
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    // If there are remaining terms in poly1
    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->expo);
        p1 = p1->link;
    }

    // If there are remaining terms in poly2
    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->expo);
        p2 = p2->link;
    }

    printf("Resultant Polynomial after addition:\n");
    displayPoly(result);
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    printf("Create first polynomial\n");
    poly1 = createPoly(poly1);
    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Create second polynomial\n");
    poly2 = createPoly(poly2);
    printf("Second Polynomial: ");
    displayPoly(poly2);

    addPoly(poly1, poly2);

    return 0;
}