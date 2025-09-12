#include <stdio.h>

int main() {
    long long n;
    printf("Enter an integer: ");
    scanf("%lld", &n);
    long long x = (n < 0) ? -n : n;
    long long sum = 0;
    while (x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    printf("Sum of digits = %lld\n", sum);
    return 0;
}
