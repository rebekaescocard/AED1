#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int vizinho;
    struct no *proximo;
}no;

typedef struct Grafo{
    int numero_vertices;
    no **lista_adj;
}Grafo;

no *criar_no(int v){
    no *novo_no = (no *)malloc(sizeof(no));
    if (novo_no == NULL){ 
        exit(1);
    }
    novo_no->vizinho = v;
    novo_no->proximo = NULL;
    return novo_no;
}

Grafo *criar_grafo(int V){
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    if (grafo == NULL){ 
        exit(1);
    }
    grafo->numero_vertices = V;

    grafo->lista_adj = (no **)malloc((V + 1) * sizeof(no *)); 
    if (grafo->lista_adj == NULL){
        exit(1);
    }

    for (int i = 1; i <= V; i++){
        grafo->lista_adj[i] = NULL;
    }
    return grafo;
}

void adiciona_aresta(Grafo *grafo, int u, int v){
    no *novo_no = criar_no(v);
    novo_no->proximo = grafo->lista_adj[u];
    grafo->lista_adj[u] = novo_no;
}

int ciclo(Grafo *grafo, int u, int *estado){
    estado[u] = 1; 

    no *temp = grafo->lista_adj[u];
    while (temp != NULL) {
        int v = temp->vizinho;
        if (estado[v] == 1){
            return 1;
        }
        if (estado[v] == 0){
            if (ciclo(grafo, v, estado)){
                return 1; 
            }
        }
        temp = temp->proximo;
    }
    estado[u] = 2; 
    return 0; 
}

int detecta_ciclo(Grafo *grafo) {
    int *estado = (int *)calloc(grafo->numero_vertices + 1, sizeof(int));
    if (estado == NULL){ 
        exit(1);
    }

    for (int i = 1; i <= grafo->numero_vertices; i++){
        if (estado[i] == 0){ 
            if (ciclo(grafo, i, estado)){
                free(estado);
                return 1; 
            }
        }
    }
    free(estado);
    return 0; 
}

void libera_grafo(Grafo *grafo){
    for (int i = 1; i <= grafo->numero_vertices; i++){
        no *p = grafo->lista_adj[i];
        no *proximo;
        while (p != NULL){
            proximo = p->proximo;
            free(p);
            p = proximo;
        }
    }
    free(grafo->lista_adj);
    free(grafo);
}

int main(){
    int T, N, M, U, V;

    if (scanf("%d", &T) != 1){
        return 0;
    }

    while (T--){
        if (scanf("%d %d", &N, &M) != 2){ 
            break;
        }
        Grafo *grafo = criar_grafo(N);

        for (int i = 0; i < M; i++){
            if (scanf("%d %d", &U, &V) != 2){ 
                break;
            }
            adiciona_aresta(grafo, U, V);
        }
        if (detecta_ciclo(grafo)){
            printf("IMPOSSIVEL\n");
        } 
        else{
            printf("POSSIVEL\n");
        }
        libera_grafo(grafo);
    }
    return 0;
}
