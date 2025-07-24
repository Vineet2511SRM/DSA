// Nested Structure Example in C

#include<stdio.h>
struct Details { // first structure 
    int MobileNumber;
    char Profession[20];
    float Salary;
};

struct Person { // second structure 
    char name[50];
    int age;
    char hobby[30];
    struct Details det; // Nested structure
};

int main() {
    struct Person p;

    // Taking input for the person
    printf("Enter name: ");
    fgets(p.name, sizeof(p.name), stdin);
    
    printf("Enter age: ");
    scanf("%d", &p.age);
    
    printf("Enter hobby: ");
    getchar(); // To consume the newline character left by previous scanf
    fgets(p.hobby, sizeof(p.hobby), stdin);

    // Taking input for the nested structure
    printf("Enter mobile number: ");
    scanf("%d", &p.det.MobileNumber); // use of nested structure 
    
    printf("Enter profession: ");
    getchar(); // To consume the newline character left by previous scanf
    fgets(p.det.Profession, sizeof(p.det.Profession), stdin);
    
    printf("Enter salary: ");
    scanf("%f", &p.det.Salary);

    // Displaying the information
    printf("\n--- Person Information ---\n");
    printf("Name: %s", p.name);
    printf("Age: %d\n", p.age);
    printf("Hobby: %s", p.hobby);
    
    printf("\n--- Details ---\n");
    printf("Mobile Number: %d\n", p.det.MobileNumber);
    printf("Profession: %s", p.det.Profession);
    printf("Salary: %.2f\n", p.det.Salary);

    return 0;
}