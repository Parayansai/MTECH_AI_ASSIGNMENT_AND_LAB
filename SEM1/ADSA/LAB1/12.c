#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    long long r = (long long) sqrt((double) n);
    for (long long i = 3; i <= r; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    long long n;
    printf("Enter number: ");
    scanf("%lld", &n);
    printf("%lld is %s\n", n, is_prime(n) ? "prime" : "not prime");
    return 0;
}
