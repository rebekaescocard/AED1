#include <stdio.h>
#include <stdlib.h>

int comparar_decrescente(const void *a, const void *b) {
    int nota_a = *(const int *)a;
    int nota_b = *(const int *)b;
    return nota_b - nota_a;
}

void resolve_caso_teste() {
    int N; 
    if (scanf("%d", &N) != 1) return;

    int *fila_original = (int *)malloc(N * sizeof(int));
    int *fila_ordenada = (int *)malloc(N * sizeof(int));

    if (fila_original == NULL || fila_ordenada == NULL) {
        if (fila_original) free(fila_original);
        if (fila_ordenada) free(fila_ordenada);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &fila_original[i]) != 1) {
            N = i; 
            break; 
        }
        fila_ordenada[i] = fila_original[i];
    }

    qsort(fila_ordenada, N, sizeof(int), comparar_decrescente);

    int posicoes_mantidas = 0;
    for (int i = 0; i < N; i++) {
        if (fila_original[i] == fila_ordenada[i]) {
            posicoes_mantidas++;
        }
    }
    printf("%d\n", posicoes_mantidas);

    free(fila_original);
    free(fila_ordenada);
}

int main() {
    int C; 
    if (scanf("%d", &C) != 1) return 0;

    while (C--) {
        resolve_caso_teste();
    }
    return 0;
}