#include <stdio.h>

struct Date {
    int day, month, year;
};

int isEarlier(struct Date a, struct Date b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

int main() {
    struct Date d1 = {10,5,2020};
    struct Date d2 = {9,12,2019};

    if (isEarlier(d1,d2))
        printf("Date1 is earlier\n");
    else
        printf("Date2 is earlier\n");


        
}
