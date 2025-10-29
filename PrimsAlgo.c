#include <stdio.h>

#define N 101 
#define INF 1999999999 

int n;
int adj[N][N], k[N], p[N], m[N];

int main() {
    int m_all, s, i, j, c, u, v, w;
    long long t = 0; 

    scanf("%d %d", &n, &m_all);
    scanf("%d", &s);

    for (i = 1; i <= n; i++) {
        k[i] = INF; 
        m[i] = 0;   
        p[i] = -1;  
        for (j = 1; j <= n; j++) adj[i][j] = INF;
    }

    for (i = 0; i < m_all; i++) {
        scanf("%d %d %d", &u, &v, &w);
        if (w < adj[u][v]) adj[u][v] = adj[v][u] = w;
    }

    k[s] = 0; 

    puts("Vertex add order:");
    for (c = 0; c < n; c++) {
        u = -1;
        int min_k = INF;
        for (v = 1; v <= n; v++) {
            if (!m[v] && k[v] < min_k) {
                min_k = k[v];
                u = v;
            }
        }

        if (u == -1) {
            puts("NO_MST");
            return 1;
        }

        m[u] = 1;
        t += min_k;
        printf("Added %d (key %d)\n", u, min_k);

        for (v = 1; v <= n; v++) {
            if (adj[u][v] < INF && !m[v] && adj[u][v] < k[v]) {
                k[v] = adj[u][v];
                p[v] = u;
            }
        }
    }

    puts("\nFinal MST edges:");
    for (i = 1; i <= n; i++) {
        if (i != s) {
            printf("(%d -> %d, %d)\n", p[i], i, k[i]);
        }
    }
    printf("Total: %lld\n", t);

    return 0;
}
