#include <stdio.h>

int main() {
    int a=45;
    int b=22;

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swap: a = %d, b = %d\n", a, b);
}
