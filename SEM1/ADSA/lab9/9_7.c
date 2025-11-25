#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* new_node(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

Node* buildBalancedFromSorted(int arr[], int l, int r) {
    if (l > r) return NULL;
    int mid = l + (r - l) / 2;
    Node* root = new_node(arr[mid]);
    root->left = buildBalancedFromSorted(arr, l, mid - 1);
    root->right = buildBalancedFromSorted(arr, mid + 1, r);
    return root;
}

typedef struct Q {
    Node** data;
    int head, tail, cap;
} Q;

Q* q_create(int cap) {
    Q* q = malloc(sizeof(Q));
    q->data = malloc(sizeof(Node*) * cap);
    q->head = q->tail = 0;
    q->cap = cap;
    return q;
}
void q_push(Q* q, Node* n) { q->data[q->tail++] = n; }
Node* q_pop(Q* q) { return q->data[q->head++]; }
int q_empty(Q* q) { return q->head == q->tail; }
void q_free(Q* q) { free(q->data); free(q); }

void levelOrder(Node* root) {
    if (!root) { printf("(empty)\n"); return; }
    Q* q = q_create(1000);
    q_push(q, root);
    while (!q_empty(q)) {
        int levelCount = q->tail - q->head;
        for (int i = 0; i < levelCount; ++i) {
            Node* cur = q_pop(q);
            printf("%d ", cur->key);
            if (cur->left) q_push(q, cur->left);
            if (cur->right) q_push(q, cur->right);
        }
        printf("\n");
    }
    q_free(q);
}

int main(void) {
    int sorted[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(sorted)/sizeof(sorted[0]);
    Node* root = buildBalancedFromSorted(sorted, 0, n-1);
    printf("Level-order traversal of balanced BST:\n");
    levelOrder(root);
    return 0;
}
