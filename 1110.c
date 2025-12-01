#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int queue[60];
        int front = 0, rear = n - 1;

        for (int i = 0; i < n; i++)
            queue[i] = i + 1;

        printf("Discarded cards:");

        while (front != rear) {

            printf(" %d", queue[front]);
            front = (front + 1) % n;

            if (front != rear)
                printf(",");

            rear = (rear + 1) % n;
            queue[rear] = queue[front];
            front = (front + 1) % n;
        }

        printf("\nRemaining card: %d\n", queue[front]);
    }

    return 0;

}
