#include <stdio.h>
#include <string.h>

void buildPostOrder(char *pre, char *in, int n) {
    if (n <= 0) return;

    char root = pre[0];

    int pos;
    for (pos = 0; pos < n; pos++) {
        if (in[pos] == root) break;
    }

    buildPostOrder(pre + 1, in, pos);

    buildPostOrder(pre + pos + 1, in + pos + 1, n - pos - 1);

    printf("%c", root);
}

int main() {
    char pre[50], in[50];

    while (scanf("%s %s", pre, in) != EOF) {
        int n = strlen(pre);
        buildPostOrder(pre, in, n);
        printf("\n");
    }

    return 0;
}