#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int cmp_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int pares[n], impares[n];
    int p = 0, i = 0;

    for (int k = 0; k < n; k++) {
        int x;
        scanf("%d", &x);

        if (x % 2 == 0)
            pares[p++] = x;
        else
            impares[i++] = x;
    }

    qsort(pares, p, sizeof(int), cmp_asc);

    qsort(impares, i, sizeof(int), cmp_desc);

    for (int k = 0; k < p; k++)
        printf("%d\n", pares[k]);

    for (int k = 0; k < i; k++)
        printf("%d\n", impares[k]);

    return 0;
}