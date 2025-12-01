#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int queue[60];
        int front = 0, rear = n - 1;

        // inicializa a fila de 1 a n
        for (int i = 0; i < n; i++)
            queue[i] = i + 1;

        printf("Discarded cards:");

        // enquanto houver mais de 1 carta
        while (front != rear) {

            // descarta a carta do topo
            printf(" %d", queue[front]);
            front = (front + 1) % n;

            if (front != rear)
                printf(",");

            // move a próxima carta para o final
            rear = (rear + 1) % n;
            queue[rear] = queue[front];
            front = (front + 1) % n;
        }

        printf("\nRemaining card: %d\n", queue[front]);
    }

    return 0;
}