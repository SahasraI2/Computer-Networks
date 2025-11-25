#include <stdio.h>

#define INF 99
#define MAX 10

int main() {
    int n, cost[MAX][MAX], visited[MAX];
    int i, j, edges = 0, u, v, min, total = 0;

    printf("Enter number of hosts: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (99 for no direct link):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
        visited[i] = 0;
    }

    visited[0] = 1; // Start from first host

    printf("\nBroadcast Tree (using Prim's MST):\n");
    while (edges < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("Edge %c - %c (Cost %d)\n", 'A' + u, 'A' + v, min);
        total += min;
        visited[v] = 1;
        edges++;
    }
    printf("Total cost of broadcast tree = %d\n", total);

    return 0;
}
