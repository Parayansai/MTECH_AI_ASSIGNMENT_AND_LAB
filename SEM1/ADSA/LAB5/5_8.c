#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
};

int main() {
    struct node *head = NULL, *tail = NULL;
    struct node *newnode;

    for (int i = 0; i < 10; i++) {
        newnode = malloc(sizeof(struct node));
        newnode->x = i;
        newnode->next = NULL;

        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    printf("Original list:\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }
    printf("\n");

    // delete at beginning
    if (head != NULL) {
        struct node *t = head;
        head = head->next;
        free(t);
    }

    printf("\nAfter deleting from beginning:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }
    printf("\n");

    // delete from end
    if (head != NULL) {
        if (head->next == NULL) {
            // only one node
            free(head);
            head = NULL;
        } else {
            struct node *p = head;
            while (p->next->next != NULL) {
                p = p->next;
            }
            free(p->next);
            p->next = NULL;
        }
    }

    printf("\nAfter deleting from end:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }
    printf("\n");

    // delete in between
    int pos;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty.\n");
    } else if (pos <= 1) {
        struct node *t = head;
        head = head->next;
        free(t);
    } else {
        struct node *p = head;
        for (int i = 1; i < pos - 1 && p->next != NULL; i++) {
            p = p->next;
        }
        if (p->next == NULL) {
            printf("Position out of range.\n");
        } else {
            struct node *to_delete = p->next;
            p->next = to_delete->next;
            free(to_delete);
        }
    }

    printf("\nAfter deleting from given position:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }
    printf("\n");

    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
