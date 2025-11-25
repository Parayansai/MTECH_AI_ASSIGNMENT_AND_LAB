#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* new_node(int k) {
    Node* n = malloc(sizeof(Node));
    n->key = k; n->left = n->right = NULL;
    return n;
}

int height_and_check(Node* root, int *isBalanced) {
    if (!root) return 0;
    int lh = height_and_check(root->left, isBalanced);
    int rh = height_and_check(root->right, isBalanced);
    if (abs(lh - rh) > 1) *isBalanced = 0;
    return (lh > rh ? lh : rh) + 1;
}

void printBalanceFactors(Node* root) {
    if (!root) return;
    printBalanceFactors(root->left);
    int lh = root->left ? height_and_check(root->left, &(int){1}) : 0;
    int rh = root->right ? height_and_check(root->right, &(int){1}) : 0;
    int bf = lh - rh;
    printf("Node %d: Balance Factor = %d\n", root->key, bf);
    printBalanceFactors(root->right);
}

int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh>rh?lh:rh) + 1;
}

void printBF_using_height(Node* root) {
    if (!root) return;
    printBF_using_height(root->left);
    int lh = height(root->left);
    int rh = height(root->right);
    printf("Node %d: Balance Factor = %d\n", root->key, lh - rh);
    printBF_using_height(root->right);
}

int isBalanced(Node* root) {
    int flag = 1;
    height_and_check(root, &flag);
    return flag;
}

int main(void) {
    Node* root = new_node(1);
    root->right = new_node(2);
    root->right->right = new_node(3);

    printf("Balance factors (inorder):\n");
    printBF_using_height(root);

    if (isBalanced(root)) printf("Tree is height-balanced (AVL property holds)\n");
    else printf("Tree is NOT height-balanced\n");

    return 0;
}
