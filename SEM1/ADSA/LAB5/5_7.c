#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
};

struct node* create_node(int val) {
    struct node* n = malloc(sizeof *n);
    n->x = val;
    n->next = NULL;
    return n;
}

void append(struct node **head, int val) {
    struct node *newnode = create_node(val);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    
}

void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->x);
        head = head->next;
    }
    printf("\n");
}

struct node* merge_sorted(struct node *a, struct node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct node *head = NULL;   // head of merged list
    struct node *tail = NULL;   // tail for appending

    if (a->x <= b->x) {
        head = tail = a;
        a = a->next;
    } 
    else {
        head = tail = b;
        b = b->next;
    }

    // Merge the lists
    while (a != NULL && b != NULL) {
        if (a->x <= b->x) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a != NULL) {
        tail->next = a;
    }
    else {
        tail->next = b;
    }

    return head;
}

void free_list(struct node *head) {
    while (head != NULL) {
        struct node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    struct node *list1 = NULL;
    struct node *list2 = NULL;

    // Example: both already sorted
    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);
    append(&list1, 7);

    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);
    append(&list2, 8);

    printf("List 1: ");
    print_list(list1);

    printf("List 2: ");
    print_list(list2);

    struct node *merged = merge_sorted(list1, list2);

    printf("Merged List: ");
    print_list(merged);

    free_list(merged);
    return 0;
}
