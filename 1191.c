#include <stdio.h>
#include <string.h>

void pos_ordem(char *pre, char *in, int n){
    if (n <= 0){ 
        return;
    }

    char raiz = pre[0];

    int pos;
    for (pos = 0; pos < n; pos++){
        if (in[pos] == raiz){ 
            break;
        }
    }
    pos_ordem(pre + 1, in, pos);
    pos_ordem(pre + pos + 1, in + pos + 1, n - pos - 1);
    printf("%c", raiz);
}

int main(){
    char pre[50], in[50];

    while (scanf("%s %s", pre, in) != EOF){
        int n = strlen(pre);
        pos_ordem(pre, in, n);
        printf("\n");
    }
    return 0;
}
