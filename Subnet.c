#include <stdio.h>
#define MAX 20

int n;
int distance[MAX];

// Function to find the minimum non-zero value in an array
int min(int arr[], int len) {
    int mini = 9999;
    for (int i = 0; i < len; i++) {
        if (arr[i] != 0 && arr[i] < mini) {
            mini = arr[i];
        }
    }
    return mini;
}

int main() {
    int adj[MAX][MAX], adj1[MAX][MAX], flag[MAX];
    int i, j, root, x, source;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the source for broadcasting: ");
    scanf("%d", &source);

    // Initialize MST adjacency matrix
    for (root = 0; root < n; root++) {
        for (i = 0; i < n; i++) {
            distance[i] = adj[root][i];
        }
        x = min(distance, n);
        for (i = 0; i < n; i++) {
            if (distance[i] == x) {
                adj1[root][i] = x;
                adj1[i][root] = x;
            } else {
                adj1[root][i] = 0;
            }
        }
    }

    // Ensure symmetry in MST
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj1[i][j] != 0) {
                adj1[j][i] = adj1[i][j];
            }
        }
    }

    // Print Original Adjacency Matrix
    printf("\nGiven adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    // Print Minimal Spanning Tree
    printf("\nMinimal Spanning Tree (MST):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj1[i][j]);
        }
        printf("\n");
    }

    // Broadcasting process
    for (i = 0; i < n; i++)
        flag[i] = 0;

    root = source;
    flag[root] = 1;

    printf("\nBroadcasting sequence:\n");
    int done = 0;
    while (!done) {
        int sent = 0;
        for (i = 0; i < n; i++) {
            if (adj1[root][i] != 0 && flag[root] == 1 && flag[i] != 1) {
                printf("Router %d sends message to Router %d\n", root, i);
                flag[i] = 1;
                sent = 1;
            }
        }

        root = (root + 1) % n;

        // Check if all routers have received the message
        done = 1;
        for (i = 0; i < n; i++) {
            if (flag[i] == 0) {
                done = 0;
                break;
            }
        }

        if (!sent && done) break;
    }

    return 0;
}
