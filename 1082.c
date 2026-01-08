#include <stdio.h>
#include <stdlib.h>

int mat[26][26];
int visitado[26];
char componente[27];
int cont_componente;

int compara(const void *a, const void *b){
    return (*(char *)a - *(char *)b);
}

void dfs(int u, int v){
    visitado[u] = 1;
    componente[cont_compoente++] = u + 'a';

    for (int i = 0; i < v; i++){
        if (mat[u][i] && !visitado[i]){
            dfs(i, v);
        }
    }
}

int main(){
    int n, v, e, i, j, k, x, y;
    char c1, c2;

    if (scanf("%d", &n) == EOF){ 
        return 0;
    }

    for (i = 1; i <= n; i++){
        scanf("%d %d", &v, &e);

        for (x = 0; x < 26; x++){
            visitado[x] = 0; 
            for (y = 0; y < 26; y++){
                mat[x][y] = 0; 
            }
        }

        for (j = 0; j < e; j++){
            scanf(" %c %c", &c1, &c2);
            mat[c1 - 'a'][c2 - 'a'] = 1;
            mat[c2 - 'a'][c1 - 'a'] = 1;
        }

        printf("caso #%d:\n", i);
        int numero_componentes = 0;

        for (j = 0; j < v; j++){
            if (!visitado[j]){
                cont_componente = 0;
                dfs(j, v);
                
                qsort(componente, cont_componente, sizeof(char), compara);
                
                for (k = 0; k < cont_componente; k++){
                    printf("%c,", componente[k]);
                }
                printf("\n");
                numero_componentes++;
            }
        }
        printf("%d connected components\n\n", numero_componentes);
    }
    return 0;
}
