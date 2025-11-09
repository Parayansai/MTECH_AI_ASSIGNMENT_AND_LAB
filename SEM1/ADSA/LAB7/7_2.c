#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    struct Node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    printf("%d popped from stack.\n", val);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    struct Node *ptr = top;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeStack() {
    struct Node *ptr = top;
    while (ptr) {
        struct Node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    top = NULL;
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Operations (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value to push: ");
            if (scanf("%d", &value) != 1) {
                printf("Invalid input.\n");
                int c; while ((c = getchar()) != '\n' && c != EOF) {}
                continue;
            }
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            display();
        }
        else if (choice == 5) {
            printf("Exiting and freeing stack...\n");
            freeStack();
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }
}
