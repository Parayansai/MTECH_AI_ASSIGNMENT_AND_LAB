#include <stdio.h>

int main() {
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);
    if (n <= 0) { printf("No elements\n"); return 0; }

    long long a;
    long long max;
    printf("Enter element 1: ");
    scanf("%lld", &a);
    max = a;
    for (int i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%lld", &a);
        if (a > max) max = a;
    }
    printf("Maximum = %lld\n", max);
    return 0;
}
