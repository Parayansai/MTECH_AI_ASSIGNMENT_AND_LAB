#include <stdio.h>

int main() {
    long long n, rev = 0;
    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) return 0;

    long long x = (n < 0) ? -n : n;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    if (n < 0) rev = -rev;
    printf("Reversed: %lld\n", rev);
    return 0;
}
