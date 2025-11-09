#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int top = -1;
int capacity = 0;

void push(char c) {
    if (top == capacity - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop_char() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int main() {
    char a[] = "parayan";               
    int len = (int)strlen(a);            

    capacity = len;
    stack = (char *)malloc(capacity * sizeof(char));

    for (int i = 0; i < len; ++i) {
        push(a[i]);
    }

    char reversed[len + 1];  
    int idx = 0;
    while (top != -1) {
        reversed[idx++] = pop_char();
    }
    reversed[idx] = '\0';

    printf("Original : %s\n", a);
    printf("Reversed : %s\n", reversed);

    free(stack);
    return 0;
}
