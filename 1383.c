#include <stdio.h>

int linha(int mat[9][9]) {
    for (int i = 0; i < 9; i++){
        int freq[10] = {0};
        for (int j = 0; j < 9; j++){
            int val = mat[i][j];
            if (val < 1 || val > 9 || freq[val]){
                return 0;
            }
            freq[val] = 1;
        }
    }
    return 1;
}

int coluna(int mat[9][9]){
    for (int j = 0; j < 9; j++){
        int freq[10] = {0};
        for (int i = 0; i < 9; i++){
            int val = mat[i][j];
            if (val < 1 || val > 9 || freq[val]){
                return 0;
            }
            freq[val] = 1;
        }
    }
    return 1;
}

int quadrado(int mat[9][9]){
    for (int x = 0; x < 9; x += 3){
        for (int y = 0; y < 9; y += 3){
            int freq[10] = {0};
            for (int i = x; i < x + 3; i++){
                for (int j = y; j < y + 3; j++){
                    int val = mat[i][j];
                    if (val < 1 || val > 9 || freq[val]){
                        return 0;
                    }
                    freq[val] = 1;
                }
            }
        }
    }
    return 1;
}

int eh_sudoku(int mat[9][9]){
    return linha(mat) && coluna(mat) && quadrado(mat);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int inst = 1; inst <= n; inst++){
        int mat[9][9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf("%d", &mat[i][j]);
            }
        }

        printf("Instancia %d\n", inst);
        if (eh_sudoku(mat)){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;

}
