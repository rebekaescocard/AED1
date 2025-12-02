#include <stdio.h>

int main() {
    int n, x;
    int freq[2001] = {0};  
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        freq[x]++;
    }

    for (int i = 1; i <= 2000; i++) {
        if (freq[i] > 0)
            printf("%d aparece %d vez(es)\n", i, freq[i]);
    }

    return 0;
}