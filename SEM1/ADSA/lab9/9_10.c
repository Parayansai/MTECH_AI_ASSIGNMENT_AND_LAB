#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

int max(int a,int b){ return a>b?a:b; }
Node* new_node(int k){ Node* n = malloc(sizeof(Node)); n->key=k; n->left=n->right=NULL; n->height=1; return n; }
int height(Node* n){ return n? n->height:0; }
int getBalance(Node* n){ return n? height(n->left)-height(n->right) : 0; }

Node* rightRotate(Node* y){
    Node* x = y->left; Node* T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node* leftRotate(Node* x){
    Node* y = x->right; Node* T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* minValueNode(Node* node) {
    Node* cur = node;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

Node* balance_and_report(Node* node) {
    if (!node) return node;
    node->height = max(height(node->left), height(node->right)) + 1;
    int bf = getBalance(node);

    if (bf > 1) {
        if (getBalance(node->left) >= 0) {
            printf("Rotation performed: Right Rotation (LL) at node %d\n", node->key);
            return rightRotate(node);
        } else {
            printf("Rotation performed: Left-Right Rotation (LR) at node %d\n", node->key);
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (bf < -1) {
        if (getBalance(node->right) <= 0) {
            printf("Rotation performed: Left Rotation (RR) at node %d\n", node->key);
            return leftRotate(node);
        } else {
            printf("Rotation performed: Right-Left Rotation (RL) at node %d\n", node->key);
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

Node* avlDelete(Node* root, int key) {
    if (!root) {
        printf("Key %d not found\n", key);
        return root;
    }
    if (key < root->key) root->left = avlDelete(root->left, key);
    else if (key > root->key) root->right = avlDelete(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {

                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = avlDelete(root->right, temp->key);
        }
    }
    if (!root) return root;
    return balance_and_report(root);
}

int treeHeight(Node* root){ return height(root); }

void levelOrder(Node* root) {
    if (!root) { printf("(empty)\n"); return; }
    Node* q[1000]; int h=0,t=0;
    q[t++]=root;
    while (h<t) {
        int cnt = t-h;
        for (int i=0;i<cnt;i++){
            Node* n = q[h++];
            printf("%d ", n->key);
            if (n->left) q[t++]=n->left;
            if (n->right) q[t++]=n->right;
        }
        printf("\n");
    }
}

Node* avlInsert(Node* node, int key) {
    if (!node) return new_node(key);
    if (key < node->key) node->left = avlInsert(node->left, key);
    else if (key > node->key) node->right = avlInsert(node->right, key);
    else return node;
    node->height = max(height(node->left), height(node->right)) + 1;
    int bf = getBalance(node);
    if (bf > 1 && key < node->left->key) return rightRotate(node);
    if (bf < -1 && key > node->right->key) return leftRotate(node);
    if (bf > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }
    if (bf < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node); }
    return node;
}

int main(void) {
    Node* root = NULL;
    int inserts[] = {9,5,10,0,6,11,-1,1,2}; 
    for (int i=0;i< (int)(sizeof(inserts)/sizeof(inserts[0])); i++)
        root = avlInsert(root, inserts[i]);

    printf("Initial AVL (level-order):\n");
    levelOrder(root);
    printf("Initial height: %d\n\n", treeHeight(root));

    int deletes[] = {10,9,11,0};
    for (int i=0;i< (int)(sizeof(deletes)/sizeof(deletes[0])); i++){
        int k = deletes[i];
        printf("\nDeleting %d:\n", k);
        root = avlDelete(root, k);
        printf("Level-order after deletion:\n");
        levelOrder(root);
        printf("Height after deletion: %d\n", treeHeight(root));
    }

    return 0;
}
