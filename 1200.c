#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char dados;
    struct No *esq;
    struct no *dir;
}no;

no* novo_no(char dados){
    no* no = (no*) malloc(sizeof(no));
    no->dados = dados;
    no->esq = no->dir = NULL;
    return no;
}

no* inserir(no* raiz, char dados){
    if (raiz == NULL){ 
        return novo_no(dados);
    }
    if (dados < raiz->dados){
        raiz->esq = inserir(raiz->esq, dados);
    }
    if (dados > raiz->dados){
        raiz->dir = inserir(raiz->dir, dados);
    }
    return raiz;
}

int busca(no* raiz, char dados){
    if (raiz == NULL){ 
        return 0;
    }
    if (raiz->dados == dados){ 
        return 1;
    }
    if (dados < raiz->dados){ 
        return busca(raiz->esq, dados);
    }
    else{
        return busca(raiz->dir, dados);
    }
}

void infixa(no* raiz, int *primeiro){
    if (raiz != NULL){
        infixa(raiz->esq, primeiro);
        if (!*primeiro){ 
            printf(" ");
        }
        printf("%c", raiz->dados);
        *primeiro = 0;
        infixa(raiz->dir, primeiro);
    }
}

void prefixa(no* raiz, int *primeiro){
    if (raiz != NULL){
        if (!*primeiro){ 
            printf(" ");
        }
        printf("%c", raiz->dados);
        *primeiro = 0;
        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

void posfixa(no* raiz, int *primeiro){
    if (raiz != NULL){
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);
        if (!*primeiro){ 
            printf(" ");
        }
        printf("%c", raiz->dados);
        *primeiro = 0;
    }
}

int main(){
    no* raiz = NULL;
    char ordem[20], c;

    while (scanf("%s", ordem) != EOF){
        if (strcmp(ordem, "I") == 0){
            scanf(" %c", &c);
            raiz = inserir(raiz, c);
        } 
        if (strcmp(ordem, "P") == 0){
            scanf(" %c", &c);
            if (busca(raiz, c)){
                printf("%c existe\n", c);
            }
            else{
                printf("%c nao existe\n", c);
            }
        } 
        if (strcmp(ordem, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        } 
        if (strcmp(ordem, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        } 
        if (strcmp(ordem, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
    }
    return 0;
}
