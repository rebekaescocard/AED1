#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void levelOrder(Node* root) {
    if (!root) return;
    Node* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int first = 1;
    while (front < rear) {
        Node* cur = queue[front++];
        if (first) {
            printf("%d", cur->val);
            first = 0;
        } else {
            printf(" %d", cur->val);
        }
        if (cur->left) queue[rear++] = cur->left;
        if (cur->right) queue[rear++] = cur->right;
    }
    printf("\n");
}


void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int t, n, val;
    scanf("%d", &t); 
    for (int c = 1; c <= t; c++) {
        scanf("%d", &n); 
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            root = insert(root, val);
        }
        printf("Case %d:\n", c);
        levelOrder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}