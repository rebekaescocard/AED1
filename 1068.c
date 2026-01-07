#include <stdio.h>
#include <string.h>

int main() {
    char expressao[1001]; 
    
    while (scanf("%s", expressao) != EOF) {
        int balanco = 0;
        int erro = 0; 

        for (int i = 0; i < strlen(expressao); i++) {
            char c = expressao[i];

            if (c == '(') {
                balanco++;
            } 
            
            if (c == ')') {
                balanco--;
                if (balanco < 0) {
                    erro = 1;
                    break; 
                }
            }
        }

        if (erro == 0 && balanco == 0) {
            printf("correto\n");
        } 
        else {
            printf("incorreto\n");
        }
    }
    
    return 0;

}
