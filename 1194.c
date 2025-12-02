#include <stdio.h>
#include <string.h>

char prefix[60], infix[60];

void buildPostOrder(int preStart, int inStart, int len) {
    if (len <= 0) return;

    char root = prefix[preStart];

    int rootIndex = 0;
    while (infix[inStart + rootIndex] != root)
        rootIndex++;

    int leftLen = rootIndex;
    int rightLen = len - leftLen - 1;

    buildPostOrder(preStart + 1, inStart, leftLen);

    buildPostOrder(preStart + 1 + leftLen, inStart + leftLen + 1, rightLen);

    putchar(root);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d %s %s", &n, prefix, infix);

        buildPostOrder(0, 0, n);
        putchar('\n');
    }

    return 0;
}