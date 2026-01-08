#include <stdio.h>

int enfilera[20010];
int visitado[10005];
int frente;
int fim;

int inverter(int x){
    int reverso = 0;
    while (x > 0){
        reverso = reverso * 10 + (x % 10);
        x /= 10;
    }
    return reverso;
}

int bfs(int A, int B){
    for (int i = 0; i < 10005; i++){
        visitado[i] = -1;
    }
    frente = fim = 0;

    enfilera[fim++] = A;
    visitado[A] = 0;

    while (frente < fim){
        int u = enfilera[frente++];
        if (u == B){ 
            return visitado[u];
        }

        if (u + 1 < 10005 && visitado[u+1] == -1){
            visitado[u+1] = visitado[u] + 1;
            enfilera[fim++] = u+1;
        }

        int v = inverter(u);
        if (v < 10005 && visitado[v] == -1){
            visitado[v] = visitado[u] + 1;
            enfilera[fim++] = v;
        }
    }
    return -1; 
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    return 0;
}
