#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *create_node(int val) {
    Node *p = malloc(sizeof(Node));
    if (!p) { perror("malloc"); exit(EXIT_FAILURE); }
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

typedef struct {
    Node **arr;
    int front, rear, size, cap;
} Queue;

Queue *create_queue(int cap) {
    Queue *q = malloc(sizeof(Queue));
    if (!q) { perror("malloc"); exit(EXIT_FAILURE); }
    q->arr = malloc(sizeof(Node*) * cap);
    if (!q->arr) { perror("malloc"); exit(EXIT_FAILURE); }
    q->front = q->size = 0;
    q->rear = cap - 1;
    q->cap = cap;
    return q;
}

int is_empty(Queue *q) { return q->size == 0; }
int is_full(Queue *q)  { return q->size == q->cap; }

void enqueue(Queue *q, Node *node) {
    if (is_full(q)) {
        q->cap *= 2;
        q->arr = realloc(q->arr, sizeof(Node*) * q->cap);
        if (!q->arr) { perror("realloc"); exit(EXIT_FAILURE); }
    }
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = node;
    q->size++;
}

Node *dequeue(Queue *q) {
    if (is_empty(q)) return NULL;
    Node *node = q->arr[q->front];
    q->front = (q->front + 1) % q->cap;
    q->size--;
    return node;
}

void free_queue(Queue *q) { free(q->arr); free(q); }

Node *build_level_order() {
    int val;
    printf("Enter root value (-1 for empty tree): ");
    scanf("%d", &val);
    if (val == -1) return NULL;

    Node *root = create_node(val);
    Queue *q = create_queue(10);
    enqueue(q, root);

    while (!is_empty(q)) {
        Node *curr = dequeue(q);
        int lval, rval;

        printf("Enter left child of %d (-1 for none): ", curr->data);
        scanf("%d", &lval);
        if (lval != -1) {
            curr->left = create_node(lval);
            enqueue(q, curr->left);
        }

        printf("Enter right child of %d (-1 for none): ", curr->data);
        scanf("%d", &rval);
        if (rval != -1) {
            curr->right = create_node(rval);
            enqueue(q, curr->right);
        }
    }

    free_queue(q);
    return root;
}

void level_order(Node *root) {
    if (!root) {
        printf("Tree is empty.\n");
        return;
    }

    Queue *q = create_queue(20);
    enqueue(q, root);

    printf("Level-order traversal: ");
    while (!is_empty(q)) {
        Node *curr = dequeue(q);
        printf("%d ", curr->data);
        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
    printf("\n");

    free_queue(q);
}

void free_tree(Node *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    Node *root = build_level_order();
    level_order(root);
    free_tree(root);
    return 0;
}
