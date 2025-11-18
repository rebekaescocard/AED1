#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct No {
    int v;
    struct No* prox;
} No;

No* adj[MAX];
int visitado[MAX];
int count;

void addaresta(int u, int v) {
    No* no = (No*) malloc(sizeof(No));
    no->v = v;
    no->prox = adj[u];
    adj[u] = no;
}

void dfs(int u) {
    visitado[u] = 1;
    No* p = adj[u];
    while (p != NULL) {
        int v = p->v;
        if (!visitado[v]) {
            count++;        
            dfs(v);
        }
        p = p->prox;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int start, n, m;
        scanf("%d %d %d", &start, &n, &m);

        for (int i = 0; i < n; i++) {
            adj[i] = NULL;
            visitado[i] = 0;
        }
        count = 0;

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addaresta(u, v);
            addaresta(v, u); 
        }

        dfs(start);

        printf("%d\n", count * 2); 
    }
    return 0;
}