#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char data;
    struct No *esq, *dir;
} No;

No* novoNo(char data) {
    No* no = (No*) malloc(sizeof(No));
    no->data = data;
    no->esq = no->dir = NULL;
    return no;
}

No* insert(No* root, char data) {
    if (root == NULL) return novoNo(data);
    if (data < root->data)
        root->esq = insert(root->esq, data);
    else if (data > root->data)
        root->dir = insert(root->dir, data);
    return root;
}

int search(No* root, char data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    if (data < root->data) return search(root->esq, data);
    else return search(root->dir, data);
}

void inorder(No* root, int *first) {
    if (root != NULL) {
        inorder(root->esq, first);
        if (!*first) printf(" ");
        printf("%c", root->data);
        *first = 0;
        inorder(root->dir, first);
    }
}

void preorder(No* root, int *first) {
    if (root != NULL) {
        if (!*first) printf(" ");
        printf("%c", root->data);
        *first = 0;
        preorder(root->esq, first);
        preorder(root->dir, first);
    }
}

void postorder(No* root, int *first) {
    if (root != NULL) {
        postorder(root->esq, first);
        postorder(root->dir, first);
        if (!*first) printf(" ");
        printf("%c", root->data);
        *first = 0;
    }
}

int main() {
    No* root = NULL;
    char command[20], c;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "I") == 0) {
            scanf(" %c", &c);
            root = insert(root, c);
        } else if (strcmp(command, "P") == 0) {
            scanf(" %c", &c);
            if (search(root, c))
                printf("%c existe\n", c);
            else
                printf("%c nao existe\n", c);
        } else if (strcmp(command, "INFIXA") == 0) {
            int first = 1;
            inorder(root, &first);
            printf("\n");
        } else if (strcmp(command, "PREFIXA") == 0) {
            int first = 1;
            preorder(root, &first);
            printf("\n");
        } else if (strcmp(command, "POSFIXA") == 0) {
            int first = 1;
            postorder(root, &first);
            printf("\n");
        }
    }
    return 0;
}