#include <stdio.h>

long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    if (n <= 0) { printf("No terms to print.\n"); return 0; }
    printf("Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib(i));
    }
    printf("\n");
    return 0;
}
