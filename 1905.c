#include <stdio.h>

#define N 5

int grid[N][N];
int visited[N][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return 0; 
    if (grid[x][y] == 1 || visited[x][y]) return 0;   

    visited[x][y] = 1;

    if (x == N-1 && y == N-1) return 1; 

    for (int i = 0; i < 4; i++) {
        if (dfs(x + dx[i], y + dy[i])) return 1;
    }

    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &grid[i][j]);
                visited[i][j] = 0;
            }
        }

        if (dfs(0, 0)) {
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }
    }

    return 0;
}