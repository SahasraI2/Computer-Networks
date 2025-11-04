#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10
#define INF INT_MAX

int minDistance(int dist[], int sptSet[], int nodes) {
    int min = INF, min_index = -1;
    for (int v = 0; v < nodes; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%c ", j + 'a');
        return;
    }
    printPath(parent, parent[j]);
    printf("%c ", j + 'a');
}

void printSolution(int dist[], int parent[], int nodes, int src, int dest) {
    printf("Shortest path from %c to %c is: ", src + 'a', dest + 'a');
    printPath(parent, dest);
    printf("\nTotal cost (delay): %d\n", dist[dest]);
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int nodes, int src, int dest) {
    int dist[MAX_NODES];
    int sptSet[MAX_NODES];
    int parent[MAX_NODES];

    for (int i = 0; i < nodes; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < nodes - 1; count++) {
        int u = minDistance(dist, sptSet, nodes);
        if (u == -1) break;
        sptSet[u] = 1;

        for (int v = 0; v < nodes; v++) {
            if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == INF)
        printf("No path exists from %c to %c.\n", src + 'a', dest + 'a');
    else
        printSolution(dist, parent, nodes, src, dest);
}

int main() {
    int nodes;
    int graph[MAX_NODES][MAX_NODES];
    char source, destination;

    printf("\nShortest Path (Dijkstra's Algorithm)\n");
    printf("*****************************************\n");

    printf("Enter the number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &nodes);

    printf("Enter the adjacency matrix for the graph (-1 for no edge):\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source node (a - %c): ", 'a' + nodes - 1);
    scanf(" %c", &source);

    printf("Enter the destination node (a - %c): ", 'a' + nodes - 1);
    scanf(" %c", &destination);

    dijkstra(graph, nodes, source - 'a', destination - 'a');

    return 0;
}
