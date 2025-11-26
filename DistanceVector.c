#include <stdio.h>

#define INF 99
#define MAX 10

int main() {
    int n, cost[MAX][MAX], dist[MAX][MAX], nextHop[MAX][MAX];
    int i, j, k;
    int updated;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    // Input cost matrix
    for (i = 0; i < n; i++) {
        printf("Enter costs from Router %c:\n", 'A' + i);
        for (j = 0; j < n; j++) {
            if (i == j) cost[i][j] = 0;
            else {
                printf("Cost to Router %c (99 if not adjacent): ", 'A' + j);
                scanf("%d", &cost[i][j]);
            }
            dist[i][j] = cost[i][j];
            nextHop[i][j] = (cost[i][j] < INF && i != j) ? j : -1;
        }
    }

    // Bellman-Ford relaxation until convergence
    do {
        updated = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        nextHop[i][j] = nextHop[i][k];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    // Display routing tables
    for (i = 0; i < n; i++) {
        printf("\nRouting table for Router %c\n", 'A' + i);

        printf("Destinations: ");
        for (j = 0; j < n; j++) printf("%c ", 'A' + j);

        printf("\nNext Hop   : ");
        for (j = 0; j < n; j++)
            printf("%c ", (nextHop[i][j] == -1) ? '-' : 'A' + nextHop[i][j]);

        printf("\nCost       : ");
        for (j = 0; j < n; j++) printf("%d ", dist[i][j]);

        printf("\n");
    }

    return 0;
}
