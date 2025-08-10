#include <stdio.h>
#include <string.h> // required for strcpy

typedef struct pokemon {
    int hp;
    int speed;
    int attack;
    char tier;
    char name[20];
} Pokemon;

int main() {
    Pokemon a, b, c;

    // Assign values to 'a'
    a.hp = 100;
    a.speed = 50;
    a.attack = 70;
    a.tier = 'A';
    strcpy(a.name, "Pikachu");

    // Deep copy using Structure
    b = a; // Copies all fields from a to b

    // Change 'b' to prove it's a separate copy
    b.hp = 80;
    strcpy(b.name, "Raichu");

    // Display both
    printf("Pokemon A: %s | HP: %d | Speed: %d | Attack: %d | Tier: %c\n",
           a.name, a.hp, a.speed, a.attack, a.tier);
    printf("Pokemon B: %s | HP: %d | Speed: %d | Attack: %d | Tier: %c\n",
           b.name, b.hp, b.speed, b.attack, b.tier);

    return 0;
}
