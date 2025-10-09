#include <stdio.h>
#include <stdlib.h>

#define tam 9

int linha(int **mat) {
    for (int i = 0; i < tam; i++) {
        int freq[10] = {0};
        for (int j = 0; j < tam; j++) {
            int val = mat[i][j];
            if (val < 1 || val > 9 || freq[val]) return 0;
            freq[val] = 1;
        }
    }
    return 1;
}

int coluna(int **mat) {
    for (int j = 0; j < tam; j++) {
        int freq[10] = {0};
        for (int i = 0; i < tam; i++) {
            int val = mat[i][j];
            if (val < 1 || val > 9 || freq[val]) return 0;
            freq[val] = 1;
        }
    }
    return 1;
}

int quadrado(int **mat) {
    for (int x = 0; x < tam; x += 3) {
        for (int y = 0; y < tam; y += 3) {
            int freq[10] = {0};
            for (int i = x; i < x + 3; i++) {
                for (int j = y; j < y + 3; j++) {
                    int val = mat[i][j];
                    if (val < 1 || val > 9 || freq[val]) return 0;
                    freq[val] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int inst = 1; inst <= n; inst++) {
        
        int **mat = (int **)malloc(tam * sizeof(int *));
        for (int i = 0; i < tam; i++)
            mat[i] = (int *)malloc(tam * sizeof(int));

        
        for (int i = 0; i < tam; i++)
            for (int j = 0; j < tam; j++)
                scanf("%d", &mat[i][j]);

        
        printf("Instancia %d\n", inst);
        if (linha(mat) && coluna(mat) && quadrado(mat))
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");

        
        for (int i = 0; i < tam; i++)
            free(mat[i]);
        free(mat);
    }

    return 0;
}