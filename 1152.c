#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u, v, w;
}vertice;

int pai[200000];

int encontrar(int x){
    if (pai[x] == x){ 
        return x;
    }
    return pai[x] = encontrar(pai[x]);
}

void unir(int a, int b){
    a = encontrar(a);
    b = encontrar(b);
    if (a != b){ 
        pai[b] = a;
    }
}

int cmp(const void *a, const void *b){
    return ((vertice*)a)->w - ((vertice*)b)->w;
}

int main(){
    int m, n;
    while (1){
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0){ 
            break;
        }

        vertice vertices[n];
        int total = 0;

        for (int i = 0; i < n; i++){
            scanf("%d %d %d", &vertices[i].u, &vertices[i].v, &vertices[i].w);
            total += vertices[i].w;
        }

        for (int i = 0; i < m; i++){
            pai[i] = i;
        }

        qsort(vertices, n, sizeof(vertice), cmp);

        int quantidade = 0;
        for (int i = 0; i < n; i++){
            if (encontrar(vertices[i].u) != encontrar(vertices[i].v)){
                unir(vertices[i].u, vertices[i].v);
                quantidade += vertices[i].w;
            }
        }

        printf("%d\n", total - quantidade);
    }
    return 0;

}
