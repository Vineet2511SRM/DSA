#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 9999
typedef struct {
    int u, v, weight;
} Edge;
int parent[MAX];
int rank[MAX];
void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}
int main() {
    int n, e;
    Edge edges[MAX];
    int i, totalCost = 0;   
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges (u v weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    qsort(edges, e, sizeof(Edge), compareEdges);
    initialize(n);
    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("Edge %d: (%d - %d) weight: %d\n", i + 1, u, v, edges[i].weight);
            totalCost += edges[i].weight;
        }
    }
    printf("\nMinimum total cost = %d\n", totalCost);
    return 0;
}



