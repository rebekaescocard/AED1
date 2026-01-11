#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dados;
    struct No *esq;
    struct No *dir;
}No;

No* novo_no(int dados){
    No* no = (No*)malloc(sizeof(No));
    no->dados = dados;
    no->esq = no->dir = NULL;
    return no;
}

No* inserir(No* raiz, int dados){
    if (raiz == NULL){ 
        return novo_no(dados);
    }
    if (dados < raiz->dados){
        raiz->esq = inserir(raiz->esq, dados);
    }
    else{
        raiz->dir = inserir(raiz->dir, dados);
    }
    return raiz;
}

void ordem_nivel(No* raiz){
    if (!raiz){ 
        return;
    }
    No* enfilera[10000];
    int frente = 0; 
    int fim = 0;
    enfilera[fim++] = raiz;

    int primeiro = 1;
    while (frente < fim){
        No* atual = enfilera[frente++];
        if (primeiro){
            printf("%d", atual->dados);
            primeiro = 0;
        } 
        else{
            printf(" %d", atual->dados);
        }
        if (atual->esq){ 
            enfilera[fim++] = atual->esq;
        }
        if (atual->dir){ 
            enfilera[fim++] = atual->dir;
        }
    }
    printf("\n");
}


void libera_arvore(No* raiz){
    if (!raiz){ 
        return;
    }
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main(){
    int t, n, dados;
    scanf("%d", &t); 
    for (int c = 1; c <= t; c++){
        scanf("%d", &n); 
        No* raiz = NULL;
        for (int i = 0; i < n; i++){
            scanf("%d", &dados);
            raiz = inserir(raiz, dados);
        }
        printf("caso %d:\n", c);
        ordem_nivel(raiz);
        printf("\n");
        libera_arvore(raiz);
    }
    return 0;
}
