#include <stdio.h>
#include <string.h>

#define MAX 10005

int queue[MAX*2];
int dist[MAX*2];
int front, rear;

int invert(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

int bfs(int A, int B) {
    memset(dist, -1, sizeof(dist));
    front = rear = 0;

    queue[rear++] = A;
    dist[A] = 0;

    while (front < rear) {
        int u = queue[front++];
        if (u == B) return dist[u];

        if (u + 1 < MAX && dist[u+1] == -1) {
            dist[u+1] = dist[u] + 1;
            queue[rear++] = u+1;
        }

        int v = invert(u);
        if (v < MAX && dist[v] == -1) {
            dist[v] = dist[u] + 1;
            queue[rear++] = v;
        }
    }
    return -1; 
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    return 0;
}