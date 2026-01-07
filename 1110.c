#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int enfilera[60];
        int frente = 0, fim = n - 1;

        for (int i = 0; i < n; i++){
            enfilera[i] = i + 1;
        }

        printf("cartas descartadas:");

        while (frente != fim) {

            printf(" %d", enfilera[frente]);
            frente = (frente + 1) % n;

            if (frente != fim){
                printf(",");
            }

            fim = (fim + 1) % n;
            enfilera[fim] = enfilera[frente];
            frente = (frente + 1) % n;
        }

        printf("\ncartas restantes: %d\n", enfilera[frente]);
    }

    return 0;

}

