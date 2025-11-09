#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
    struct node *prev;
};


void deleteValue(struct node **head, struct node **tail, int value) {
    struct node *temp = *head;

    while (temp != NULL && temp->x != value)
        temp = temp->next;

    if (temp == NULL)
        return; 

    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        else
            *tail = NULL; 
    }

    else if (temp == *tail) {
        *tail = temp->prev;
        (*tail)->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
}

int main(void) {
    int i;
    struct node *y;
    struct node *head = NULL;
    struct node *tail = NULL;

    for (i = 0; i < 10; i++) {
        y = malloc(sizeof *y);
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

    printf("List before deletion:\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->x);
        temp = temp->next;
    }

    int val;
    printf("Enter value to delete (first occurrence): ");
    if (scanf("%d", &val) == 1) {
        deleteValue(&head, &tail, val);

        printf("List after deletion:\n");
        temp = head;
        while (temp != NULL) {
            printf("%d\n", temp->x);
            temp = temp->next;
        }
    } else {
        printf("Invalid input.\n");
    }

    struct node *cur = head;
    struct node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }

}
