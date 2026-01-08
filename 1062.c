#include <stdio.h>
#include <stdlib.h>

int simula_trilhos(int N, const int B[]){
    int *pilha = (int *)malloc(N * sizeof(int));
    if (pilha == NULL){
        return 0; 
    }

    int topo = -1; 
    int proximo_vagao_entrada = 1;
    int indice_saida = 0; 

    while (indice_saida < N){
        int desejado = B[indice_saida];

        if (topo != -1 && pilha[topo] == desejado){
            topo--; 
            indice_saida++; 
            continue; 
        }
        if (proximo_vagao_entrada <= N && proximo_vagao_entrada == desejado){
            proximo_vagao_entrada++; 
            indice_saida++; 
            continue; 
        }
        if (proximo_vagao_entrada <= N){
            topo++;
            pilha[topo] = proximo_vagao_entrada;
            proximo_vagao_entrada++;
        } 
        else{
            free(pilha);
            return 0; 
        }
    }
    free(pilha);
    return 1;
}

int main(){
    int N;

    while (scanf("%d", &N) && N != 0){
        int B[1000]; 
        
        while (1){
            if (scanf("%d", &B[0]) != 1 || B[0] == 0){
                break;
            }
            for (int i = 1; i < N; i++){
                if (scanf("%d", &B[i]) != 1){
                    break;
                }
            }

            if (simula_trilhos(N, B)){
                printf("Yes\n");
            } 
            else{
                printf("No\n");
            }
        }
        printf("\n"); 
    }
    return 0;
}
