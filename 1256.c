#include <stdio.h>
#include <stdlib.h>

int main() {
    int T; 
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int M, C;
        scanf("%d %d", &M, &C);

        int *hash[M];
        int size[M];
        for (int i = 0; i < M; i++) {
            hash[i] = (int*)malloc(C * sizeof(int));
            size[i] = 0;
        }

        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);
            int pos = x % M;
            hash[pos][size[pos]++] = x;
        }

        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < size[i]; j++) {
                printf(" %d ->", hash[i][j]);
            }
            printf(" \\\n");
        }

        if (t < T - 1) printf("\n");

        for (int i = 0; i < M; i++) free(hash[i]);
    }

    return 0;
}