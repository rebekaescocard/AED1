#include <stdio.h>
#include <string.h>

#define MAX 30

int N, M;
int adj[MAX][MAX];
int visited[MAX];
char comp[MAX];
int compSize;

void dfs(int v) {
    visited[v] = 1;
    comp[compSize++] = 'a' + v;
    for (int i = 0; i < N; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);

        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < M; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            int a = u - 'a';
            int b = v - 'a';
            adj[a][b] = adj[b][a] = 1;
        }

        printf("Case #%d:\n", t);

        int components = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                compSize = 0;
                dfs(i);
                // Ordena os vértices do componente
                for (int x = 0; x < compSize; x++) {
                    for (int y = x+1; y < compSize; y++) {
                        if (comp[x] > comp[y]) {
                            char tmp = comp[x];
                            comp[x] = comp[y];
                            comp[y] = tmp;
                        }
                    }
                }
                // Imprime o componente
                for (int x = 0; x < compSize; x++) {
                    printf("%c,", comp[x]);
                }
                printf("\n");
                components++;
            }
        }

        printf("%d connected components\n\n", components);
    }

    return 0;
}