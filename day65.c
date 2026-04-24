#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
bool visited[MAX];
int V;               // Number of vertices

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // If there is an edge
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true; // Cycle found
            }
        }
    }
    return false;
}

int hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}