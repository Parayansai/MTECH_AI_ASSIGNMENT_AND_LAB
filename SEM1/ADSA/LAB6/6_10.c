#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printCircularList(struct Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void splitCircularList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    *head1_ref = NULL;
    *head2_ref = NULL;

    if (head == NULL) return;

    if (head->next == head) {
        *head1_ref = head;
        *head2_ref = NULL;
        return;
    }

    struct Node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
        fast = fast->next;


    *head1_ref = head;
    *head2_ref = slow->next;


    slow->next = *head1_ref;
    fast->next = *head2_ref;
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

    printf("\nOriginal Circular List: ");
    printCircularList(head);

    struct Node *head1 = NULL, *head2 = NULL;
    splitCircularList(head, &head1, &head2);

    printf("\nFirst half: ");
    printCircularList(head1);

    printf("Second half: ");
    printCircularList(head2);

}
