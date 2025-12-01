#include <stdio.h>
#include <math.h>

int main() {
    double valor;
    scanf("%lf", &valor);

    // Converte para centavos para evitar erros de ponto flutuante
    int centavos = (int) round(valor * 100);

    int notas[] = {10000, 5000, 2000, 1000, 500, 200}; // em centavos
    int moedas[] = {100, 50, 25, 10, 5, 1};

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        int qtd = centavos / notas[i];
        centavos %= notas[i];
        printf("%d nota(s) de R$ %.2f\n", qtd, notas[i] / 100.0);
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        int qtd = centavos / moedas[i];
        centavos %= moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", qtd, moedas[i] / 100.0);
    }

    return 0;
}