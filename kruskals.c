
#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

int parent[20];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int a = find(u);
    int b = find(v);
    parent[a] = b;
}

int main() {
    struct Edge e[50], temp;
    int n, m, i, j, count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter source, destination and weight:\n");

    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].src, &e[i].dest, &e[i].weight);
    }
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (e[j].weight > e[j + 1].weight) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < m && count < n - 1; i++) {
        int u = e[i].src;
        int v = e[i].dest;

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, e[i].weight);
            cost += e[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    if (count == n - 1)
        printf("Minimum cost = %d\n", cost);
    else
        printf("MST not possible. Graph is disconnected.\n");

    return 0;
}
