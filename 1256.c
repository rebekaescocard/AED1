#include <stdio.h>
#include <stdlib.h>

int main(){
    int T; 
    scanf("%d", &T);

    for (int t = 0; t < T; t++){
        int M, C;
        scanf("%d %d", &M, &C);

        int *hash[M];
        int tam[M];
        for (int i = 0; i < M; i++){
            hash[i] = (int*)malloc(C * sizeof(int));
            tam[i] = 0;
        }

        for (int i = 0; i < C; i++){
            int x;
            scanf("%d", &x);
            int posicao = x % M;
            hash[posicao][tam[posicao]++] = x;
        }

        for (int i = 0; i < M; i++){
            printf("%d ->", i);
            for (int j = 0; j < tam[i]; j++){
                printf(" %d ->", hash[i][j]);
            }
            printf(" \\\n");
        }

        if (t < T - 1){ 
            printf("\n");
        }

        for (int i = 0; i < M; i++){ 
            free(hash[i]);
        }
    }
    return 0;
}
