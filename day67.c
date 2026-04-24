#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

// Push to stack
void push(int node) {
    stack[++top] = node;
}

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    // Perform DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order
    printf("Topological Ordering:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}