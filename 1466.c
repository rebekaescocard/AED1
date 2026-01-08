#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dados;
    struct no *esq;
    struct no *dir;
}no;

no* novo_no(int dados){
    no* no = (no*)malloc(sizeof(no));
    no->dados = dados;
    no->esq = no->dir = NULL;
    return no;
}

no* inserir(no* raiz, int dados){
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

void ordem_nivel(no* raiz){
    if (!raiz){ 
        return;
    }
    no* enfilera[10000];
    int frente = 0; 
    int fim = 0;
    enfilera[fim++] = raiz;

    int primeiro = 1;
    while (frente < fim){
        no* atual = enfilera[frente++];
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


void libera_arvore(no* raiz){
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
        no* raiz = NULL;
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
