#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int poder;
    int matou;
    int morreu;
}guerreiro;

int compara(const void *a, const void *b){
    guerreiro *x = (guerreiro*)a;
    guerreiro *y = (guerreiro*)b;

    if (x->poder != y->poder){
        return y->poder - x->poder;
    }
    if (x->matou != y->matou){ 
        return y->matou - x->matou;
    }
    if (x->morreu != y->morreu){ 
        return x->morreu - y->morreu;
    }
    return strcmp(x->nome, y->nome); 
}

int main(){
    int N;
    scanf("%d", &N);

    guerreiro guerreiros[N];
    for (int i = 0; i < N; i++){
        scanf("%s %d %d %d", guerreiros[i].nome, &guerreiros[i].poder,&guerreiros[i].matou, &guerreiros[i].morreu);
    }

    qsort(guerreiros, N, sizeof(guerreiro), compara);
    printf("%s\n", guerreiros[0].nome);

    return 0;
}
