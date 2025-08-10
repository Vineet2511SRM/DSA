// Basic structure

#include<stdio.h>

int main(){
    struct Pokemon { // User defined data type
        int hp;
        int speed;
        int attack;
        char tier;
    };

    struct Pokemon pikachu; // Variable of type Pokemon
    printf("Enter health power of Pikachu : \n ");
    scanf("%d", &pikachu.hp);
    printf("Enter speed of Pikachu : \n ");
    scanf("%d", &pikachu.speed);
    printf("Enter attack of Pikachu : \n ");
    scanf("%d", &pikachu.attack);
    printf("Enter tier of Pikachu : \n ");
    scanf(" %c", &pikachu.tier);

    struct Pokemon charizard;
    printf("Enter health power of Charizard : \n ");
    scanf("%d", &charizard.hp);
    printf("Enter speed of Charizard : \n ");
    scanf("%d", &charizard.speed);
    printf("Enter attack of Charizard : \n ");
    scanf("%d", &charizard.attack);
    printf("Enter tier of Charizard : \n ");
    scanf(" %c", &charizard.tier);

    struct Pokemon Mewtwo;
    printf("Enter health power of Mewtwo : \n ");
    scanf("%d", &Mewtwo.hp);
    printf("Enter speed of Mewtwo : \n ");
    scanf("%d", &Mewtwo.speed);
    printf("Enter attack of Mewtwo : \n ");
    scanf("%d", &Mewtwo.attack);
    printf("Enter tier of Mewtwo : \n ");
    scanf(" %c", &Mewtwo.tier);

    printf("Printing details of Pikachu : \n ");
    printf("Health Power : %d\n", pikachu.hp);
    printf("Speed : %d\n", pikachu.speed);
    printf("Attack : %d\n", pikachu.attack);
    printf("Tier : %c\n", pikachu.tier);

    printf("Printing details of Charizard : \n ");
    printf("Health Power : %d\n", charizard.hp);
    printf("Speed : %d\n", charizard.speed);
    printf("Attack : %d\n", charizard.attack);
    printf("Tier : %c\n", charizard.tier);

    printf("Printing details of Mewtwo : \n ");
    printf("Health Power : %d\n", Mewtwo.hp);
    printf("Speed : %d\n", Mewtwo.speed);
    printf("Attack : %d\n", Mewtwo.attack);
    printf("Tier : %c\n", Mewtwo.tier);

}