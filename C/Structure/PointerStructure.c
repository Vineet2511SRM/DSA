#include <stdio.h>
#include <string.h>

// Define the structure
typedef struct person {
    int age;
    char name[25];
    int weight;
} person;

int main() {
    person p1;       // Structure variable
    person *ptr;     // Pointer to structure

    ptr = &p1;       // Assign address of p1 to ptr

    // Taking input using pointer
    printf("Enter name: ");
    fgets(ptr->name, sizeof(ptr->name), stdin);
    ptr->name[strcspn(ptr->name, "\n")] = '\0'; // Remove newline

    printf("Enter age: ");
    scanf("%d", &ptr->age);

    printf("Enter weight: ");
    scanf("%d", &ptr->weight);

    // Displaying values using pointer
    printf("\n--- Person Details ---\n");
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    printf("Weight: %d\n", ptr->weight);

    return 0;
}
