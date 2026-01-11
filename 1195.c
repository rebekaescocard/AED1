#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dados;
    struct no *esq;
    struct no *dir;
}no;

no* criar_no(int valor){
    no* novo_no = (no*)malloc(sizeof(no));
    if (novo_no == NULL){
        exit(1);
    }
    novo_no->dados = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

no* inserir(no* raiz, int valor){
    if (raiz == NULL){ 
        return criar_no(valor);
    }
    if (valor < raiz->dados){
        raiz->esq = inserir(raiz->esq, valor);
    }
    else{
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void prefixa(no* raiz){
    if (raiz != NULL){
        printf(" %d", raiz->dados);
        prefixa(raiz->esq);
        prefixa(raiz->dir);
    }
}

void infixa(no* raiz){
    if (raiz != NULL){
        infixa(raiz->esq);
        printf(" %d", raiz->dados);
        infixa(raiz->dir);
    }
}

void posfixa(no* raiz){
    if (raiz != NULL){
        posfixa(raiz->esq);
        posfixa(raiz->dir);
        printf(" %d", raiz->dados);
    }
}

void libera_arvore(no* raiz){
    if (raiz != NULL){
        libera_arvore(raiz->esq);
        libera_arvore(raiz->dir);
        free(raiz);
    }
}

int main(){
    int c, n, valor;
    if (scanf("%d", &c) == EOF){ 
        return 0;
    }

    for (int i = 1; i <= c; i++){
        no* raiz = NULL;
        scanf("%d", &n);
        for (int j = 0; j < n; j++){
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("caso %d:", i);
        
        printf("\npre:");
        prefixa(raiz);
        
        printf("\nin:");
        infixa(raiz);
        
        printf("\npos:");
        posfixa(raiz);
        
        printf("\n\n");
        
        libera_arvore(raiz);
    }
    return 0;
}
