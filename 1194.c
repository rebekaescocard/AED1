#include <stdio.h>
#include <string.h>

char prefixa[60], infixa[60];

void pos_ordem(int pre_ordem, int in_ordem, int tam){
    if (tam <= 0){
        return;
    }

    char raiz = prefixa[pre_ordem];

    int indice_raiz = 0;
    while (infixa[in_ordem + indice_raiz] != raiz){
        indice_raiz++;
    }

    int esq_tam = indice_raiz;
    int dir_tam = tam - esq_tam - 1;

    pos_ordem(pre_ordem + 1, in_ordem, esq_tam);
    pos_ordem(pre_ordem + 1 + esq_tam, in_ordem + esq_tam + 1, dir_tam);
    printf("%c", raiz);
}

int main(){
    int t;
    scanf("%d", &t);

    while (t--){
        int n;
        scanf("%d %s %s", &n, prefixa, infixa);
        pos_ordem(0, 0, n);
        printf("\n");
    }
    return 0;
}
