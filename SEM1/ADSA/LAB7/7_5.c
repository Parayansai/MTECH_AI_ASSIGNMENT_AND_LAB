#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1)  
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    front++;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Operations ---\n");
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
