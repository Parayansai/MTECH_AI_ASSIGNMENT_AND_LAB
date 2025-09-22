#include <stdio.h>

void printNumbers(int n) {
    if (n == 0){ 
        return;
    }
    printNumbers(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printNumbers(n);
}
