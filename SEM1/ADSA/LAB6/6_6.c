#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **head, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

void insertAtEnd(struct node **head, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    // find last node
    struct node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Circular linked list: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
            
                if (head != NULL) {
                    struct node *temp = head->next, *nextNode;
                    while (temp != head) {
                        nextNode = temp->next;
                        free(temp);
                        temp = nextNode;
                    }
                    free(head);
                }
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
