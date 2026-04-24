#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

// DFS function to detect cycle
bool dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            // If not visited, recurse
            if (!visited[i] && dfs(i))
                return true;
            // If already in recursion stack → cycle
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    // Check cycle
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}