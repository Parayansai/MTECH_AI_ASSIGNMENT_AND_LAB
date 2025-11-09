#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL)
        return;

    struct Node *curr = *head_ref, *prev = NULL;

    if (curr->data == key) {
        if (curr->next == *head_ref) {
            free(curr);
            *head_ref = NULL;
            return;
        }

        struct Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;

        temp->next = curr->next;
        *head_ref = curr->next;
        free(curr);
        return;
    }

    prev = curr;
    curr = curr->next;

    while (curr != *head_ref) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Node with value %d not found.\n", key);
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, data, delValue;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List cannot be empty.\n");
        return 0;
    }

    int i = 0;
    while (i < n) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; 
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head;  
            temp = newNode;
        }
        i++;
    }

    printf("\nOriginal Circular Linked List: ");
    printList(head);

    printf("\nEnter the value to delete: ");
    scanf("%d", &delValue);

    deleteNode(&head, delValue);

    printf("List after deleting %d: ", delValue);
    printList(head);

    return 0;
}
