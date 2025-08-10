#include <stdio.h>
#include <string.h>

typedef struct date {
    int day;
    int month;
    int year;
} date; // added name for typedef

int main() {
    date a, b;

    // a -> 25/11/2005
    // b -> 15/05/2006
    a.day = 25;
    a.month = 11;
    a.year = 2005;

    b.day = 15;
    b.month = 5;
    b.year = 2006;

    // Comparison
    if (a.day == b.day && a.month == b.month && a.year == b.year) {
        printf("Dates are equal\n");
    } else {
        printf("Dates are not equal\n");
    }

    return 0;
}
