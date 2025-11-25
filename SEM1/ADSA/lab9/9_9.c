#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

int max(int a, int b){ return a>b? a: b; }

Node* new_node(int k) {
    Node* n = malloc(sizeof(Node));
    n->key = k; n->left = n->right = NULL; n->height = 1;
    return n;
}

int height(Node* n) { return n ? n->height : 0; }
int getBalance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* avlInsert(Node* node, int key) {
    if (!node) return new_node(key);
    if (key < node->key) node->left = avlInsert(node->left, key);
    else if (key > node->key) node->right = avlInsert(node->right, key);
    else return node; 

    node->height = 1 + max(height(node->left), height(node->right));
    int bf = getBalance(node);

    // LL
    if (bf > 1 && key < node->left->key) {
        printf("Rotation performed: Right Rotation (LL) at node %d\n", node->key);
        return rightRotate(node);
    }
    // RR
    if (bf < -1 && key > node->right->key) {
        printf("Rotation performed: Left Rotation (RR) at node %d\n", node->key);
        return leftRotate(node);
    }
    // LR
    if (bf > 1 && key > node->left->key) {
        printf("Rotation performed: Left-Right Rotation (LR) at node %d\n", node->key);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL
    if (bf < -1 && key < node->right->key) {
        printf("Rotation performed: Right-Left Rotation (RL) at node %d\n", node->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder_printBF(Node* root) {
    if (!root) return;
    inorder_printBF(root->left);
    printf("Node %d: BF = %d\n", root->key, getBalance(root));
    inorder_printBF(root->right);
}

void levelOrder(Node* root) {
    if (!root) { printf("(empty)\n"); return; }
    Node* q[1000]; int head=0, tail=0;
    q[tail++] = root;
    while (head < tail) {
        int cnt = tail - head;
        for (int i=0;i<cnt;i++){
            Node* n = q[head++];
            printf("%d ", n->key);
            if (n->left) q[tail++] = n->left;
            if (n->right) q[tail++] = n->right;
        }
        printf("\n");
    }
}

int main(void) {
    int keys[] = {10, 20, 30, 40, 50, 25}; 
    int n = sizeof(keys)/sizeof(keys[0]);
    Node* root = NULL;
    for (int i=0;i<n;i++){
        printf("\nInserting %d:\n", keys[i]);
        root = avlInsert(root, keys[i]);
        printf("Level-order after insertion:\n");
        levelOrder(root);
        printf("Balance factors (inorder):\n");
        inorder_printBF(root);
    }
    return 0;
}
