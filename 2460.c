#include <stdio.h>
#include <stdlib.h>
#define MAX_ID 100001

void resolve_problema() {
    int N; 
    if (scanf("%d", &N) != 1) return;
    int *fila_inicial = (int *)malloc(N * sizeof(int));
    if (fila_inicial == NULL) exit(1);

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &fila_inicial[i]) != 1) break;
    }

    int M; 
    if (scanf("%d", &M) != 1) {
        free(fila_inicial);
        return;
    }

    int *saidas = (int *)calloc(MAX_ID, sizeof(int));
    if (saidas == NULL) {
        free(fila_inicial);
        exit(1);
    }

    for (int i = 0; i < M; i++) {
        int id_saiu;
        if (scanf("%d", &id_saiu) != 1) break;
        
        if (id_saiu < MAX_ID) {
            saidas[id_saiu] = 1; 
        }
    }

    int primeira_impressao = 1; 
    
    for (int i = 0; i < N; i++) {
        int id_atual = fila_inicial[i];
        if (id_atual < MAX_ID && saidas[id_atual] == 0) {
            if (!primeira_impressao) {
                printf(" ");
            }
            printf("%d", id_atual);
            primeira_impressao = 0; 
        }
    }
    printf("\n"); 
    free(fila_inicial);
    free(saidas);
}

int main() {
    resolve_problema();
    return 0;
}