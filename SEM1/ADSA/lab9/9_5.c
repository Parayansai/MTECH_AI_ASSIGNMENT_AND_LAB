#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *create_node(int val) {
    Node *p = malloc(sizeof(Node));
    if (!p) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

Node *insert(Node *root, int val) {
    if (root == NULL) {
        return create_node(val);
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        printf("Duplicate value %d ignored (BSTs usually contain unique values)\n", val);
    return root;
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder traversal of BST (sorted order): ");
    inorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}
