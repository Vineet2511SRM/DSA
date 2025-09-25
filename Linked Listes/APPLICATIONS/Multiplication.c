// C program to multiply two polynomials
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

void multiplyPoly(struct node* head1, struct node* head2) {
    struct node* result = NULL;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;

    // Multiply each term of the first polynomial with each term of the second polynomial
    while (ptr1 != NULL) {
        if (head1==NULL || head2==NULL){
            printf("Multiplication not possible\n");
            return;
        }
        ptr2 = head2; // Reset ptr2 to the head of the second polynomial
        while (ptr2 != NULL) {
            float coeffProduct = ptr1->coeff * ptr2->coeff;
            int expoSum = ptr1->expo + ptr2->expo;
            result = insert(result, coeffProduct, expoSum);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    printf("Resultant Polynomial before simplification: ");
    displayPoly(result);

    // Simplify the resultant polynomial by combining like terms
    struct node* temp = NULL;
    struct node* ptr3 = result;
    while(ptr3->link != NULL) {
        if(ptr3->expo == ptr3->link->expo) {
            ptr3->coeff += ptr3->link->coeff;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
            temp = NULL;
        } else {
            ptr3 = ptr3->link;
        }
    }

    printf("Resultant Polynomial after simplification: ");
    displayPoly(result);
}
int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    printf("Create first polynomial\n");
    head1 = createPoly(head1);
    printf("First Polynomial: ");
    displayPoly(head1);

    printf("Create second polynomial\n");
    head2 = createPoly(head2);
    printf("Second Polynomial: ");
    displayPoly(head2);

    multiplyPoly(head1, head2);

    return 0;
}