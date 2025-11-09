#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
    struct node *prev;
};

void reverseList(struct node **head, struct node **tail) {
    struct node *current = *head;
    struct node *temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;  
    }

    *tail = *head;
    while ((*tail)->next != NULL) {
        *tail = (*tail)->next;
    }
}

int main(void) {
    int i;
    struct node *y;
    struct node *head = NULL;
    struct node *tail = NULL;

    // Create doubly linked list
    for (i = 0; i < 10; i++) {
        y = malloc(sizeof(struct node));
        y->x = i;
        if (head == NULL) {
            head = tail = y;
            y->prev = NULL;
            y->next = NULL;
        } else {
            tail->next = y;
            y->prev = tail;
            y->next = NULL;
            tail = y;
        }
    }

    printf("Original list:\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }

    reverseList(&head, &tail);

    printf("\nReversed list:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }

    struct node *cur = head;
    struct node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }

    return 0;
}
