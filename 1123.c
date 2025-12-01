#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 250
#define INF INT_MAX/2

typedef struct Edge {
    int v;
    int w;
    struct Edge *next;
} Edge;

Edge* adj[MAXN];
int N, M, C, K;

void add_edge(int u, int v, int w) {
    Edge* e = malloc(sizeof(Edge));
    e->v = v; e->w = w;
    e->next = adj[u];
    adj[u] = e;
    e = malloc(sizeof(Edge));
    e->v = u; e->w = w;
    e->next = adj[v];
    adj[v] = e;
}

int dijkstra() {
    int dist[MAXN];
    bool vis[MAXN] = {0};

    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[K] = 0;

    for (;;) {
        int u = -1, best = INF;
        for (int i = 0; i < N; i++) {
            if (!vis[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        vis[u] = true;

        if (u >= 0 && u < C-1) {
            int v = u+1;
            for (Edge* e = adj[u]; e != NULL; e = e->next) {
                if (e->v == v) {
                    if (dist[v] > dist[u] + e->w) {
                        dist[v] = dist[u] + e->w;
                    }
                    break;
                }
            }
        }

        if (!(u >= 0 && u < C)) {
            for (Edge* e = adj[u]; e != NULL; e = e->next) {
                int v = e->v;
                int w = e->w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    return dist[C-1] >= INF ? -1 : dist[C-1];
}

int main(){
    while (scanf("%d %d %d %d", &N, &M, &C, &K)==4) {
        if (N==0 && M==0 && C==0 && K==0) break;

        for (int i = 0; i < N; i++) {
            adj[i] = NULL;
        }

        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
        }

        int ans = dijkstra();
        if (ans < 0) printf("Impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}