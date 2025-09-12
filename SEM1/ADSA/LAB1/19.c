#include <stdio.h>

long long sum_digits(long long n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;
    return (n % 10) + sum_digits(n / 10);
}

int main() {
    long long n;
    printf("Enter integer: ");
    scanf("%lld", &n);
    printf("Sum of digits = %lld\n", sum_digits(n));
    return 0;
}
