#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int data;
    struct No *esq;
    struct No *dir;
} No;

No *criaNovoNo(int data) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) exit(1);
    novoNo->data = data;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

No *inserir(No *root, int data) {
    if (root == NULL) {
        return criaNovoNo(data);
    }
    
    if (data < root->data) {
        root->esq = inserir(root->esq, data);
    } else if (data > root->data) {
        root->dir = inserir(root->dir, data);
    }
    return root;
}

void _prefixa(No *root, int *eh_prim) {
    if (root != NULL) {
        if (*eh_prim == 0) {
            printf(" ");
        } else {
            *eh_prim = 0; 
        }
        
        printf("%d", root->data);
        
        _prefixa(root->esq, eh_prim);
        _prefixa(root->dir, eh_prim);
    }
}

void _infixa(No *root, int *eh_prim) {
    if (root != NULL) {
        _infixa(root->esq, eh_prim);
        if (*eh_prim == 0) {
            printf(" ");
        } else {
            *eh_prim = 0; 
        }
        
        printf("%d", root->data);
        
        _infixa(root->dir, eh_prim);
    }
}

void _posfixa(No *root, int *eh_prim) {
    if (root != NULL) {
        _posfixa(root->esq, eh_prim);
        _posfixa(root->dir, eh_prim);
        
        if (*eh_prim == 0) {
            printf(" ");
        } else {
            *eh_prim = 0; 
        }
        
        printf("%d", root->data);
    }
}

void deletaArvore(No *root) {
    if (root != NULL) {
        deletaArvore(root->esq);
        deletaArvore(root->dir);
        free(root);
    }
}

void resolve_caso_teste(int caso_num) {
    int N;
    if (scanf("%d", &N) != 1) return;

    No *root = NULL;
    int valor;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &valor) != 1) break;
        root = inserir(root, valor);
    }

    printf("Case %d:\n", caso_num);
    
    int eh_prim; 

    printf("Pre.:");
    eh_prim = 1; 
    _prefixa(root, &eh_prim);
    printf("\n");

    printf("In..:");
    eh_prim = 1;
    _infixa(root, &eh_prim);
    printf("\n");

    printf("Post.:");
    eh_prim = 1;
    _posfixa(root, &eh_prim);
    printf("\n");
    
    deletaArvore(root);
}

int main() {
    int C;
    if (scanf("%d", &C) != 1) return 0;

    for (int i = 1; i <= C; i++) {
        resolve_caso_teste(i);
        if (i < C) {
            printf("\n");
        }
    }
    
    return 0;
}