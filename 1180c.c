#include <stdio.h>
#include <stdlib.h>

int main(){

    int tam;
    scanf("%d", &tam);
    
    int *x = (int*)malloc(tam * sizeof(int));

    if (x == NULL){
        printf("erro ao alocar memoria\n");
        return 1;
    }

    for (int i=0; i<tam; i++){
        scanf("%d", x[i]);
    }

    int menor = x[0], posicao = 0;

    for (int i=1; i<tam; i++){
        if (x[i] < menor){
            menor = x[i];
            posicao = i; 
        }
    }

    printf("menor valor: %d\n", menor);
    printf("posicao: %d\n", posicao);

    free(x);

    return 0;
}