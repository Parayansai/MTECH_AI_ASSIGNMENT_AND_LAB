#include <stdio.h>

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long a, b;
    printf("Enter two integers: ");
    scanf("%lld %lld", &a, &b);
    printf("GCD = %lld\n", gcd(a, b));
    return 0;
}
