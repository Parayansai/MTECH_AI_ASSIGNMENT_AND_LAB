#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
    struct node *prev;
};

int main(void) {
    int i;
    struct node *y;
    struct node *head = NULL;
    struct node *tail = NULL;

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

    printf("Doubly linked list:\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->x);
        temp = temp->next;
    }
    printf("\n");

    struct node *slow = head;
    struct node *fast = head;
    int length = 0;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;   
        length += 2;                
    }

    if (fast != NULL)
        length++;

    printf("Length of the list: %d\n", length);
    printf("Middle node value: %d\n", slow->x);

    struct node *cur = head;
    struct node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }

}
