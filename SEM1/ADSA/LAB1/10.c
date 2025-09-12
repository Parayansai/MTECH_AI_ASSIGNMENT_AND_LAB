#include <stdio.h>

int main() {
    long long n;
    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) return 0;

    if (n == 0) { printf("Digits = 1\n"); return 0; }
    int count = 0;
    long long x = (n < 0) ? -n : n;
    while (x > 0) { x /= 10; count++; }
    printf("Digits = %d\n", count);
    return 0;
}
