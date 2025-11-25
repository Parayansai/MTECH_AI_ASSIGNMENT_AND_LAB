#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *create_node(int val) {
    Node *p = malloc(sizeof *p);
    if (!p) { perror("malloc"); exit(EXIT_FAILURE); }
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

typedef struct {
    Node **arr;
    int head, tail, cap;
} Queue;

Queue *q_create(int init_cap) {
    Queue *q = malloc(sizeof *q);
    if (!q) { perror("malloc"); exit(EXIT_FAILURE); }
    q->arr = malloc(sizeof(Node*) * init_cap);
    if (!q->arr) { perror("malloc"); exit(EXIT_FAILURE); }
    q->head = q->tail = 0;
    q->cap = init_cap;
    return q;
}
int q_empty(Queue *q) { return q->head == q->tail; }
void q_push(Queue *q, Node *n) {
    if (q->tail == q->cap) {
        if (q->head > 0) {
            int i = 0;
            for (int j = q->head; j < q->tail; ++j, ++i) q->arr[i] = q->arr[j];
            q->tail -= q->head;
            q->head = 0;
        } else {
            int newcap = q->cap * 2;
            Node **tmp = realloc(q->arr, sizeof(Node*) * newcap);
            if (!tmp) { perror("realloc"); exit(EXIT_FAILURE); }
            q->arr = tmp;
            q->cap = newcap;
        }
    }
    q->arr[q->tail++] = n;
}
Node *q_pop(Queue *q) { if (q_empty(q)) return NULL; return q->arr[q->head++]; }
void q_free(Queue *q) { free(q->arr); free(q); }

Node *build_level_order() {
    int val;
    printf("Enter root value (-1 for empty tree): ");
    if (scanf("%d", &val) != 1) { fprintf(stderr,"Invalid input\n"); exit(EXIT_FAILURE); }
    if (val == -1) return NULL;

    Node *root = create_node(val);
    Queue *q = q_create(64);
    q_push(q, root);

    while (!q_empty(q)) {
        Node *curr = q_pop(q);
        int left_val, right_val;

        printf("Enter left child of %d (-1 for no child): ", curr->data);
        if (scanf("%d", &left_val) != 1) { fprintf(stderr,"Invalid input\n"); q_free(q); exit(EXIT_FAILURE); }
        if (left_val != -1) {
            curr->left = create_node(left_val);
            q_push(q, curr->left);
        }

        printf("Enter right child of %d (-1 for no child): ", curr->data);
        if (scanf("%d", &right_val) != 1) { fprintf(stderr,"Invalid input\n"); q_free(q); exit(EXIT_FAILURE); }
        if (right_val != -1) {
            curr->right = create_node(right_val);
            q_push(q, curr->right);
        }
    }

    q_free(q);
    return root;
}

int is_bst_minmax(Node *root, long long min_allowed, long long max_allowed) {
    if (!root) return 1; 
    if (!( (long long)root->data > min_allowed && (long long)root->data < max_allowed )) {
        return 0;
    }
    return is_bst_minmax(root->left, min_allowed, (long long)root->data)
        && is_bst_minmax(root->right, (long long)root->data, max_allowed);
}

void free_tree(Node *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void inorder_print(Node *root) {
    if (!root) return;
    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
}

int main(void) {
    Node *root = build_level_order();

    if (!root) {
        printf("Empty tree.\n");
        return 0;
    }

    printf("\nInorder of constructed tree: ");
    inorder_print(root);
    printf("\n");

    int is_bst = is_bst_minmax(root, LLONG_MIN, LLONG_MAX);
    if (is_bst) printf("The tree IS a BST (strict ordering: left < node < right).\n");
    else       printf("The tree is NOT a BST.\n");

    free_tree(root);
    return 0;
}
