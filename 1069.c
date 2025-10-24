#include <stdio.h>
#include <string.h>

int main() {
    char linha[1000]; 
    int diamante_aberto = 0;   
    int diamante_cont = 0;  
    
    printf("Digite a linha com areia e diamantes (ex: <<.<<..>><>><.>):\n");
    if (scanf("%s", linha) != 1) {
        printf("Erro na leitura da entrada.\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(linha); i++) {
        char char_atual = linha[i];

        if (char_atual == '<') {
            diamante_aberto++;
            
        } else if (char_atual == '>') {
            if (diamante_aberto > 0) {
                diamante_aberto--;
                diamante_cont++;
            }
        }
    }
    
    printf("\nResultado:\n");
    printf("Total de diamantes capturados: %d\n", diamante_cont);
    
    return 0;
}