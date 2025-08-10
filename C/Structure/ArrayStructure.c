#include <stdio.h>

struct Student {
    char name[20];
    int roll_no;
    float cpi;
};

int main() {
    int i, n;
    printf("Enter the number of records you want to store: ");
    scanf("%d", &n);
    getchar(); // consume the newline after entering n

    struct Student sarr[n];

    for (i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", sarr[i].name); // read full line until newline
        printf("Enter the roll number of student %d: ", i + 1);
        scanf("%d", &sarr[i].roll_no);
        printf("Enter the CPI of student %d: ", i + 1);
        scanf("%f", &sarr[i].cpi);
        getchar(); // consume newline before next name
    }

    printf("\n--- Student Records ---\n");
    printf("\n\tName\t\tRoll No\tCPI\n");
    for (i = 0; i < n; i++) {
        printf("\t%-15s %d\t%.2f\n", sarr[i].name, sarr[i].roll_no, sarr[i].cpi);
    }
    printf("\n--- End of Records ---\n");

    return 0;
}
