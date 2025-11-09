#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int value) {
    if (isFull()) {
        printf("Overflow! Cannot insert %d at front.\n", value);
        return;
    }
    if (isEmpty()) {           
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX; 
    }
    deque[front] = value;
    printf("%d inserted at front.\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Overflow! Cannot insert %d at rear.\n", value);
        return;
    }
    if (isEmpty()) {           
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX; 
    }
    deque[rear] = value;
    printf("%d inserted at rear.\n", value);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Underflow! Deque is empty.\n");
        return;
    }
    int val = deque[front];
    if (front == rear) {      
        front = rear = -1;
    } else {
        front = (front + 1) % MAX; 
    }
    printf("%d deleted from front.\n", val);
}

void deleteRear() {
    if (isEmpty()) {
        printf("Underflow! Deque is empty.\n");
        return;
    }
    int val = deque[rear];
    if (front == rear) {      
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX; 
    }
    printf("%d deleted from rear.\n", val);
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements (front -> rear): ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Deque (circular array) ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { printf("Invalid input. Exiting.\n"); break; }

        if (choice == 1) {
            printf("Enter value to insert at front: ");
            if (scanf("%d", &value) != 1) { printf("Invalid input.\n"); break; }
            insertFront(value);
        }
        else if (choice == 2) {
            printf("Enter value to insert at rear: ");
            if (scanf("%d", &value) != 1) { printf("Invalid input.\n"); break; }
            insertRear(value);
        }
        else if (choice == 3) {
            deleteFront();
        }
        else if (choice == 4) {
            deleteRear();
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 6) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

}
