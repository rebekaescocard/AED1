#include <stdio.h>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, int N, int mat[N][N], int visitado[N][N]) {
    if (x < 0 || x >= N || y < 0 || y >= N){ 
        return 0;
    }
    if (mat[x][y] == 1 || visitado[x][y]){ 
        return 0;
    }

    visitado[x][y] = 1;

    if (x == N-1 && y == N-1){ 
        return 1; 
    }

    for (int i = 0; i < 4; i++){
        if (dfs(x + dx[i], y + dy[i], N, mat, visitado)){ 
            return 1;
        }
    }
    return 0;
}

int main(){
    int T, N;
    scanf("%d", &T);

    while (T--){
        scanf("%d", &N);
        int mat[N][N];
        int visitado[N][N];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                scanf("%d", &mat[i][j]);
                visitado[i][j] = 0;
            }
        }

        if (dfs(0, 0, N, mat, visitado)){
            printf("COPS\n");
        }
        else{
            printf("ROBBERS\n");
        }
    }
    return 0;
}
