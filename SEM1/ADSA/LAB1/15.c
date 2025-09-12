#include <stdio.h>

double bill_for_units(long long units) {
    if (units <= 0) return 0.0;
    double bill = 0.0;
    if (units <= 100) {
        bill = units * 5.0;
    } else if (units <= 200) {
        bill = 100 * 5.0 + (units - 100) * 7.0;
    } else {
        bill = 100 * 5.0 + 100 * 7.0 + (units - 200) * 10.0;
    }
    return bill;
}

int main() {
    long long units;
    printf("Enter units consumed: ");
    scanf("%lld", &units);
    printf("Total bill = rs%.2f\n", bill_for_units(units));
    return 0;
}
