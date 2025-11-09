#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % MAX == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1) 
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("%d enqueued to the circular queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d dequeued from the circular queue.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

}
