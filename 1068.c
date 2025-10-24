#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

int main() {
    char expressao[MAX_SIZE]; 
    
    while (scanf("%s", expressao) != EOF) {
        
        int balanco = 0;
        int correto = 1; 

        for (int i = 0; i < strlen(expressao); i++) {
            char c = expressao[i];

            if (c == '(') {
                balanco++;
            } else if (c == ')') {
                if (balanco > 0) {
                    balanco--;
                } else {
                    correto = 0;
                    break; 
                }
            }
        }

        if (correto && balanco == 0) {
            printf("correto\n");
        } else {
            printf("incorreto\n");
        }
    }
    
    return 0;
}