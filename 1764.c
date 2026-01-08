#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int origem;
    int destino;
    int peso;
}estrada;

int cmp_estradas(const void *a, const void *b){
    estrada *estrada_a = (estrada *)a;
    estrada *estrada_b = (estrada *)b;
    return estrada_a->peso - estrada_b->peso;
}

int pai(int pais[], int i){
    if (pais[i] == i){
        return i;
    }
    return pai(pais, pais[i]);
}

int kruskal(estrada estradas[], int *pais, int total_estradas){
    int i, soma_pesos = 0;
    int raiz_u, raiz_v;

    for (i = 0; i < total_estradas; ++i){
        raiz_v = pai(pais, estradas[i].origem);
        raiz_u = pai(pais, estradas[i].destino);

        if (raiz_v != raiz_u){
            pais[raiz_v] = raiz_u; 
            soma_pesos += estradas[i].peso;
        }
    }
    return soma_pesos;
}

int main(){
    int numero_cidades, numero_estradas;
    while (scanf("%d %d", &numero_cidades, &numero_estradas), numero_cidades && numero_estradas) {
        
        estrada *grafo = (estrada *)malloc(numero_estradas * sizeof(estrada));
        int *pais = (int *)malloc((numero_cidades + 1) * sizeof(int));

        for (int i = 0; i < num_estradas; ++i){
            scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);
        }

        qsort(grafo, num_estradas, sizeof(Estrada), cmp_estradas);

        for (int i = 0; i < numero_cidades; ++i){
            pais[i] = i;
        }
        
        printf("%d\n", kruskal(grafo, pais, numero_estradas));

        free(grafo);
        free(pais);
    }
    return 0;
}
