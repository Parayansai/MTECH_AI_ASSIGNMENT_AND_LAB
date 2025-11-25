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

Node *insert(Node *root, int val) {
    if (!root) return create_node(val);
    if (val < root->data) root->left  = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

Node *kth_smallest_rec(Node *root, int *k) {
    if (!root) return NULL;
    Node *res = kth_smallest_rec(root->left, k);
    if (res) return res;
    (*k)--;
    if (*k == 0) return root;
    return kth_smallest_rec(root->right, k);
}

Node *kth_largest_rec(Node *root, int *k) {
    if (!root) return NULL;
    Node *res = kth_largest_rec(root->right, k);
    if (res) return res;
    (*k)--;
    if (*k == 0) return root;
    return kth_largest_rec(root->left, k);
}

int kth_smallest(Node *root, int k, int *found) {
    if (k <= 0) { *found = 0; return INT_MIN; }
    Node *res = kth_smallest_rec(root, &k);
    if (res) { *found = 1; return res->data; }
    *found = 0;
    return INT_MIN;
}

int kth_largest(Node *root, int k, int *found) {
    if (k <= 0) { *found = 0; return INT_MIN; }
    Node *res = kth_largest_rec(root, &k);
    if (res) { *found = 1; return res->data; }
    *found = 0;
    return INT_MIN;
}

int kth_smallest_iter(Node *root, int k, int *found) {
    if (k <= 0) { *found = 0; return INT_MIN; }
    Node **stack = NULL;
    int cap = 0, top = 0;
    Node *curr = root;
    while (curr || top > 0) {
        while (curr) {
            if (top >= cap) {
                cap = cap ? cap * 2 : 16;
                stack = realloc(stack, sizeof(Node*) * cap);
                if (!stack) { perror("realloc"); exit(EXIT_FAILURE); }
            }
            stack[top++] = curr;
            curr = curr->left;
        }
        curr = stack[--top];
        k--;
        if (k == 0) { int val = curr->data; free(stack); *found = 1; return val; }
        curr = curr->right;
    }
    free(stack);
    *found = 0;
    return INT_MIN;
}

int kth_largest_iter(Node *root, int k, int *found) {
    if (k <= 0) { *found = 0; return INT_MIN; }
    Node **stack = NULL;
    int cap = 0, top = 0;
    Node *curr = root;
    while (curr || top > 0) {
        while (curr) {
            if (top >= cap) {
                cap = cap ? cap * 2 : 16;
                stack = realloc(stack, sizeof(Node*) * cap);
                if (!stack) { perror("realloc"); exit(EXIT_FAILURE); }
            }
            stack[top++] = curr;
            curr = curr->right;
        }
        curr = stack[--top];
        k--;
        if (k == 0) { int val = curr->data; free(stack); *found = 1; return val; }
        curr = curr->left;
    }
    free(stack);
    *found = 0;
    return INT_MIN;
}

void inorder_print(Node *root) {
    if (!root) return;
    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
}

void free_tree(Node *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    int n, val;

    printf("Enter number of nodes to insert into BST: ");
    if (scanf("%d", &n) != 1 || n < 0) { fprintf(stderr,"Invalid n\n"); return 1; }
    printf("Enter %d integers (space separated):\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder (sorted): ");
    inorder_print(root);
    printf("\n");

    int k;
    printf("Enter k to find k-th smallest: ");
    scanf("%d", &k);
    int found;
    int ans = kth_smallest(root, k, &found); 
    if (found) printf("Recursive: %d-th smallest = %d\n", k, ans);
    else       printf("Recursive: k=%d out of range\n", k);

    ans = kth_smallest_iter(root, k, &found);
    if (found) printf("Iterative: %d-th smallest = %d\n", k, ans);
    else       printf("Iterative: k=%d out of range\n", k);

    printf("Enter k to find k-th largest: ");
    scanf("%d", &k);
    ans = kth_largest(root, k, &found); 
    if (found) printf("Recursive: %d-th largest = %d\n", k, ans);
    else       printf("Recursive: k=%d out of range\n", k);

    ans = kth_largest_iter(root, k, &found); 
    if (found) printf("Iterative: %d-th largest = %d\n", k, ans);
    else       printf("Iterative: k=%d out of range\n", k);

    free_tree(root);
    return 0;
}
