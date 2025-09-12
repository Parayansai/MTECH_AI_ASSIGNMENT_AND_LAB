#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(long long n) {
    long long original = n, rev = 0;
    if (n < 0) return false;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev == original;
}

int main() {
    long long pin;
    printf("Enter PIN/number: ");
    scanf("%lld", &pin);
    if (is_palindrome(pin)) printf("Palindrome\n");
    else printf("Not palindrome\n");
    return 0;
}
