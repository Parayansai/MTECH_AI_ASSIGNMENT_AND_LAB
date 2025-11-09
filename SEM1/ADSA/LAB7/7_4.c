#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

static struct Node *top = NULL;

void push(char c) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) { perror("malloc"); exit(EXIT_FAILURE); }
    node->data = c;
    node->next = top;
    top = node;
}

char pop_char() {
    if (top == NULL) return '\0';
    struct Node *temp = top;
    char c = temp->data;
    top = top->next;
    free(temp);
    return c;
}

int isEmpty() {
    return top == NULL;
}

void freeStack() {
    while (top) {
        struct Node *t = top;
        top = top->next;
        free(t);
    }
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(const char *expr) {
    freeStack(); 

    for (size_t i = 0; expr[i] != '\0'; ++i) {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char topChar = pop_char();
            if (topChar == '\0') {
                return 0;
            }
            if (!isMatchingPair(topChar, ch)) {

                return 0;
            }
        }

    }

    int balanced = isEmpty();
    freeStack(); /* cleanup */
    return balanced;
}

int main() {
    char input[1001];

    printf("Enter an expression to check (max 1000 chars):\n");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Input error.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    if (isBalanced(input))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

}
