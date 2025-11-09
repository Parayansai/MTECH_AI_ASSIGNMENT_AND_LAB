#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int data;
    int priority; 
} PQItem;

PQItem pq[MAX];
int size = 0;

int isFull() {
    return size == MAX;
}

int isEmpty() {
    return size == 0;
}

void enqueue(int data, int priority) {
    if (isFull()) {
        printf("Priority Queue Overflow! Cannot insert (%d, %d)\n", data, priority);
        return;
    }
    pq[size].data = data;
    pq[size].priority = priority;
    size++;
    printf("Enqueued (data=%d, priority=%d)\n", data, priority);
}

void dequeue() {
    if (isEmpty()) {
        printf("Priority Queue Underflow! Nothing to dequeue.\n");
        return;
    }

    int maxPri = pq[0].priority;
    int idx = 0;
    for (int i = 1; i < size; ++i) {
        if (pq[i].priority > maxPri) {
            maxPri = pq[i].priority;
            idx = i;
        }
    }

    printf("Dequeued (data=%d, priority=%d)\n", pq[idx].data, pq[idx].priority);

    for (int j = idx; j < size - 1; ++j) {
        pq[j] = pq[j + 1];
    }
    size--;
}

void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("PQ contents (data,priority) from front to rear:\n");
    for (int i = 0; i < size; ++i) {
        printf("(%d,%d) ", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Priority Queue (array) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue (remove highest priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 1) {
            int d, p;
            printf("Enter data (int): ");
            scanf("%d", &d);
            printf("Enter priority (int, larger => higher priority): ");
            scanf("%d", &p);
            enqueue(d, p);
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
            printf("Invalid choice. Try again.\n");
        }
    }

}
