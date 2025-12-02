#include <stdio.h>

unsigned long long fatorial(int x) {
    unsigned long long fat = 1;
    for (int i = 2; i <= x; i++)
        fat *= i;
    return fat;
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) != EOF) {
        unsigned long long resultado = fatorial(m) + fatorial(n);
        printf("%llu\n", resultado);
    }

    return 0;
}