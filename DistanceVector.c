#include <stdio.h>
#define MAX 10
#define INF 99

int n;

struct Router {
    int dist[MAX];
    char from[MAX];
} routers[MAX];

void input() {
    for (int i = 0; i < n; i++) {
        printf("\nEnter distance from router %c to others (99 for no link):\n", 'A' + i);
        for (int j = 0; j < n; j++) {
            if (i == j) {
                routers[i].dist[j] = 0;
                routers[i].from[j] = 'A' + i;
            } else {
                printf("Distance from %c to %c: ", 'A' + i, 'A' + j);
                scanf("%d", &routers[i].dist[j]);
                if (routers[i].dist[j] != INF)
                    routers[i].from[j] = 'A' + j;
                else
                    routers[i].from[j] = '-';
            }
        }
    }
}

void build_table() {
    int updated;
    do {
        updated = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (routers[i].dist[j] > routers[i].dist[k] + routers[k].dist[j]) {
                        routers[i].dist[j] = routers[i].dist[k] + routers[k].dist[j];
                        routers[i].from[j] = 'A' + k;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);
}

void display() {
    for (int i = 0; i < n; i++) {
        printf("\nRouting Table for Router %c\n", 'A' + i);
        printf("Destination : ");
        for (int j = 0; j < n; j++)
            printf("%c ", 'A' + j);
        printf("\nNext Hop    : ");
        for (int j = 0; j < n; j++)
            printf("%c ", routers[i].from[j]);
        printf("\nCost        : ");
        for (int j = 0; j < n; j++)
            printf("%d ", routers[i].dist[j]);
        printf("\n");
    }
}

int main() {
    printf("Enter number of routers: ");
    scanf("%d", &n);

    input();
    build_table();
    display();

    return 0;
}
