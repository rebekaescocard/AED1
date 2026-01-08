#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct vertice{
    int v;
    int w;
    struct vertice *proximo;
}vertice;

vertice* mat[250];
int N, M, C, K;

void adiciona_vertice(int u, int v, int w){
    vertice* e = malloc(sizeof(vertice));
    e->v = v; e->w = w;
    e->proximo = mat[u];
    mat[u] = e;
    e = malloc(sizeof(vertice));
    e->v = u; e->w = w;
    e->proximo = mat[v];
    mat[v] = e;
}

int dijkstra(){
    int distancia[250];
    bool visitado[250] = {0};

    for (int i = 0; i < N; i++){
        distancia[i] = INF;
    }
    distancia[K] = 0;

    while (1){
    int u = -1;
    if (u == -1){ 
        break; 
    }
        if (u == -1){ 
            break;
        }
        visitado[u] = true;

        if (u >= 0 && u < C-1){
            int v = u+1;
            for (vertice* e = mat[u]; e != NULL; e = e->proximo){
                if (e->v == v){
                    if (distancia[v] > distancia[u] + e->w){
                        distancia[v] = distancia[u] + e->w;
                    }
                    break;
                }
            }
        }

        if (!(u >= 0 && u < C)){
            for (vertice* e = mat[u]; e != NULL; e = e->proximo){
                int v = e->v;
                int w = e->w;
                if (distancia[v] > distancia[u] + w){
                    distancia[v] = distancia[u] + w;
                }
            }
        }
    }

    return distancia[C-1] >= INF ? -1 : distancia[C-1];
}

int main(){
    while (scanf("%d %d %d %d", &N, &M, &C, &K)==4){
        if (N==0 && M==0 && C==0 && K==0){ 
            break;
        }

        for (int i = 0; i < N; i++){
            mat[i] = NULL;
        }

        for (int i = 0; i < M; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adiciona_vertice(u, v, w);
        }

        int resposta = dijkstra();
        if (resposta < 0){ 
            printf("Impossible\n");
        }
        else{ 
            printf("%d\n", resposta);
        }
    }
    return 0;
}
