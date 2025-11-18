#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int vizinho;
    struct No *proximo;
} No;

typedef struct Graph {
    int numVertices;
    No **adjList;
} Graph;

No *criaNovoNo(int v) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) exit(1);
    novoNo->vizinho = v;
    novoNo->proximo = NULL;
    return novoNo;
}

Graph *criaGrafo(int V) {
    Graph *grafo = (Graph *)malloc(sizeof(Graph));
    if (grafo == NULL) exit(1);
    grafo->numVertices = V;

    grafo->adjList = (No **)malloc((V + 1) * sizeof(No *)); 
    if (grafo->adjList == NULL) exit(1);

    for (int i = 1; i <= V; i++) {
        grafo->adjList[i] = NULL;
    }
    return grafo;
}

void adicionaAresta(Graph *grafo, int u, int v) {
    No *novoNo = criaNovoNo(v);
    novoNo->proximo = grafo->adjList[u];
    grafo->adjList[u] = novoNo;
}

int temCicloDFS(Graph *grafo, int u, int *estado) {
    estado[u] = 1; 

    No *temp = grafo->adjList[u];
    while (temp != NULL) {
        int v = temp->vizinho;
        if (estado[v] == 1) {
            return 1;
        }
        if (estado[v] == 0) {
            if (temCicloDFS(grafo, v, estado)) {
                return 1; 
            }
        }
        temp = temp->proximo;
    }
    estado[u] = 2; 
    return 0; 
}

int detectaCiclo(Graph *grafo) {
    int *estado = (int *)calloc(grafo->numVertices + 1, sizeof(int));
    if (estado == NULL) exit(1);

    for (int i = 1; i <= grafo->numVertices; i++) {
        if (estado[i] == 0) { 
            if (temCicloDFS(grafo, i, estado)) {
                free(estado);
                return 1; 
            }
        }
    }
    free(estado);
    return 0; 
}

void liberaGrafo(Graph *grafo) {
    for (int i = 1; i <= grafo->numVertices; i++) {
        No *p = grafo->adjList[i];
        No *proximo;
        while (p != NULL) {
            proximo = p->proximo;
            free(p);
            p = proximo;
        }
    }
    free(grafo->adjList);
    free(grafo);
}

int main() {
    int T, N, M, U, V;

    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        if (scanf("%d %d", &N, &M) != 2) break;
        Graph *grafo = criaGrafo(N);

        for (int i = 0; i < M; i++) {
            if (scanf("%d %d", &U, &V) != 2) break;
            adicionaAresta(grafo, U, V);
        }
        if (detectaCiclo(grafo)) {
            printf("IMPOSSIVEL\n");
        } else {
            printf("POSSIVEL\n");
        }
        liberaGrafo(grafo);
    }
    return 0;
}