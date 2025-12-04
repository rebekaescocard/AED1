#include <stdio.h>

typedef struct {
    int valor;
    int chamadas;
} Resultado;

Resultado fib(int n) {
    Resultado r;
    if (n == 0) {
        r.valor = 0;
        r.chamadas = 0; 
    } else if (n == 1) {
        r.valor = 1;
        r.chamadas = 0; 
    } else {
        Resultado f1 = fib(n - 1);
        Resultado f2 = fib(n - 2);
        r.valor = f1.valor + f2.valor;
        r.chamadas = f1.chamadas + f2.chamadas + 2; 
    }
    return r;
}

int main() {
    int N, x;
    scanf("%d", &N); 
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        Resultado r = fib(x);
        printf("fib(%d) = %d calls = %d\n", x, r.chamadas, r.valor);
    }

    return 0;
}