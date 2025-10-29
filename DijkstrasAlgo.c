#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 100

typedef struct Node {
    int v;
    int w;
    struct Node* next;
} Node;

typedef struct {
    int vertex;
    int dist;
} Pair;

typedef struct {
    Pair heap[MAX * MAX];
    int size;
} MinHeap;

int n;
Node* AdjW[MAX];
int dist[MAX], parent[MAX];

// ---------- Min-Heap Functions ----------
void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapPush(MinHeap *h, int vertex, int dist) {
    h->heap[h->size].vertex = vertex;
    h->heap[h->size].dist = dist;
    int i = h->size++;
    while (i > 0 && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

Pair heapPop(MinHeap *h) {
    Pair root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    int i = 0;
    while (1) {
        int left = 2*i+1, right = 2*i+2, smallest = i;
        if (left < h->size && h->heap[left].dist < h->heap[smallest].dist) smallest = left;
        if (right < h->size && h->heap[right].dist < h->heap[smallest].dist) smallest = right;
        if (smallest == i) break;
        swap(&h->heap[i], &h->heap[smallest]);
        i = smallest;
    }
    return root;
}

int heapEmpty(MinHeap *h) {
    return h->size == 0;
}

// ---------- Graph Helper ----------
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = AdjW[u];
    AdjW[u] = newNode;
}

// ---------- Dijkstra Algorithm ----------
void Dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[s] = 0;
    MinHeap pq = {.size = 0};
    heapPush(&pq, s, 0);

    while (!heapEmpty(&pq)) {
        Pair top = heapPop(&pq);
        int u = top.vertex, d = top.dist;
        if (d > dist[u]) continue;

        for (Node* temp = AdjW[u]; temp != NULL; temp = temp->next) {
            int v = temp->v, w = temp->w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                heapPush(&pq, v, dist[v]);
            }
        }
    }
}

// ---------- Path Reconstruction ----------
void printPath(int s, int t) {
    if (dist[t] == INF) {
        printf("PATH %d -> UNREACHABLE\n", t);
        return;
    }
    int path[MAX], count = 0;
    for (int x = t; x != -1; x = parent[x]) path[count++] = x;

    printf("PATH %d -> ", t);
    for (int i = count - 1; i >= 0; i--) printf("%d%s", path[i], (i ? " " : "\n"));
}

// ---------- Main ----------
int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        AdjW[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    char query[10];
    int s = -1, t;

    while (scanf("%s", query) != EOF) {
        if (query[0] == 'S') {  // SRC
            scanf("%d", &s);
            Dijkstra(s);
        } else if (query[0] == 'D') {  // DIST
            scanf("%d", &t);
            if (dist[t] == INF) printf("DIST %d -> UNREACHABLE\n", t);
            else printf("DIST %d -> %d\n", t, dist[t]);
        } else if (query[0] == 'P') {  // PATH
            scanf("%d", &t);
            printPath(s, t);
        }
    }
    return 0;
}
