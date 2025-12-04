#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int w;
} Edge;

int parent[100000], rankUF[100000];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    if (rankUF[rx] < rankUF[ry]) parent[rx] = ry;
    else if (rankUF[rx] > rankUF[ry]) parent[ry] = rx;
    else {
        parent[ry] = rx;
        rankUF[rx]++;
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0) break;

        Edge edges[m];
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rankUF[i] = 0;
        }

        qsort(edges, m, sizeof(Edge), cmp);

        long long total = 0;
        for (int i = 0; i < m; i++) {
            if (find(edges[i].u) != find(edges[i].v)) {
                unite(edges[i].u, edges[i].v);
                total += edges[i].w;
            }
        }

        printf("%lld\n", total);
    }
    return 0;
}