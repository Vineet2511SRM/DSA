#include <stdio.h>
#include <string.h> // for removing trailing newline

// Defining a structure named 'Mobile'
struct Mobile {
    char brand[50];
    char model[50];
    int year;
    float price;
    int ram;       // in GB
    int storage;   // in GB
};

// Function to remove newline from fgets
void removeNewline(char str[]) {
    str[strcspn(str, "\n")] = 0;
}

int main() {
    struct Mobile mob;

    // Taking input using fgets
    printf("Enter the mobile brand: ");
    fgets(mob.brand, sizeof(mob.brand), stdin);
    removeNewline(mob.brand);

    printf("Enter the mobile model: ");
    fgets(mob.model, sizeof(mob.model), stdin);
    removeNewline(mob.model);

    printf("Enter the mobile year: ");
    scanf("%d", &mob.year);

    printf("Enter the mobile price: ");
    scanf("%f", &mob.price);

    printf("Enter the mobile RAM (in GB): ");
    scanf("%d", &mob.ram);

    printf("Enter the mobile storage (in GB): ");
    scanf("%d", &mob.storage);

    // Displaying the information
    printf("\n--- Mobile Information ---\n");
    printf("Brand: %s\n", mob.brand);
    printf("Model: %s\n", mob.model);
    printf("Year: %d\n", mob.year);
    printf("Price: Rs %.2f\n", mob.price);
    printf("RAM: %d GB\n", mob.ram);
    printf("Storage: %d GB\n", mob.storage);

    return 0;
}
