#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Return 1 if the list is circular (some node's next eventually points back to head),
   otherwise return 0. An empty list is considered NOT circular here. */
int isCircular(struct Node* head) {
    if (head == NULL)
        return 0;

    struct Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head) ? 1 : 0;
}

void printCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* t = head;
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode = NULL;
    int n, value, i = 0;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of nodes.\n");
        return 0;
    }

    while (i < n) {
        printf("Enter data for node %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) { perror("malloc"); return 1; }
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;   
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;  
        }
        i++;
    }

    printf("\nList created. Elements: ");
    printCircularList(head);

    if (isCircular(head))
        printf("Result: The linked list is circular.\n");
    else
        printf("Result: The linked list is NOT circular.\n");


}
