#include <stdio.h>

unsigned long long factorial(int n) {
    if (n <= 1) return 1ULL;
    return (unsigned long long)n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter non-negative integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial undefined for negative numbers.\n");
        return 0;
    }
    printf("%d! = %llu\n", n, factorial(n));
    return 0;
}
