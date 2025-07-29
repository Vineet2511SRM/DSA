#include <stdio.h>

// Structure definition
struct Mobile {
    char brand[50];
    char model[50];
    int year;
    float price;
    int ram;       // in GB
    int storage;   // in GB
};

int main() {
    int n;

    printf("Enter the number of mobiles: ");
    scanf("%d", &n);

    struct Mobile mob[n]; // Array of structures

    // Input loop
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Mobile %d:\n", i + 1);

        printf("Enter mobile brand : ");
        scanf("%s", mob[i].brand); 

        printf("Enter mobile model : ");
        scanf("%s", mob[i].model);

        printf("Enter year of release: ");
        scanf("%d", &mob[i].year);

        printf("Enter price: ");
        scanf("%f", &mob[i].price);

        printf("Enter RAM (in GB): ");
        scanf("%d", &mob[i].ram);

        printf("Enter Storage (in GB): ");
        scanf("%d", &mob[i].storage);
    }

    // Output loop
    printf("\n--- Mobile Information List ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nMobile %d:\n", i + 1);
        printf("Brand: %s\n", mob[i].brand);
        printf("Model: %s\n", mob[i].model);
        printf("Year: %d\n", mob[i].year);
        printf("Price: Rs %.2f\n", mob[i].price);
        printf("RAM: %d GB\n", mob[i].ram);
        printf("Storage: %d GB\n", mob[i].storage);
    }

    return 0;
}
