#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int V;

// Find vertex with minimum distance (acts like priority queue)
int getMin() {
    int min = INT_MAX, index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int edges, u, v, w, source;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        // If undirected, also add: graph[v][u] = w;
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dist[source] = 0;

    // Dijkstra
    for (int i = 0; i < V - 1; i++) {
        int u = getMin();
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < V; i++) {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}