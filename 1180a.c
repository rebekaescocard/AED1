#include <stdio.h>

int main(){
    int n, x[n];

    scanf("%d", &n);

    for (int i=0; i<n; i++){
    scanf("%d", &x[i]);
    }

    int menor = x[0], posicao = 0;

    for (int i=1; i<n; i++){
        if (x[i] < menor){
            menor = x[i];
            posicao = i;
        }
    }

    printf("menor valor: %d\n", menor);
    printf("posicao: %d\n", posicao);

    return 0;
}