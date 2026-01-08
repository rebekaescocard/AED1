#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int v;
    struct no* prox;
}no;

no* mat[1000];
int visitado[1000];
int contador;

void addiciona_aresta(int u, int v){
    no* no = (no*) malloc(sizeof(no));
    no->v = v;
    no->prox = mat[u];
    mat[u] = no;
}

void dfs(int u){
    visitado[u] = 1;
    no* p = mat[u];
    while (p != NULL){
        int v = p->v;
        if (!visitado[v]){
            contador++;        
            dfs(v);
        }
        p = p->prox;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int inicio, n, m;
        scanf("%d %d %d", &inicio, &n, &m);

        for (int i = 0; i < n; i++){
            mat[i] = NULL;
            visitado[i] = 0;
        }
        contador = 0;

        for (int i = 0; i < m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            adiciona_aresta(u, v);
            adiciona_aresta(v, u); 
        }

        dfs(inicio);

        printf("%d\n", contador * 2); 
    }
    return 0;
}
