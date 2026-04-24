#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int V;

// Queue operations
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    // Compute indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) {
                indegree[j]++;
            }
        }
    }

    // Add all nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Ordering:\n");

    // Kahn's Algorithm
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int i = 0; i < V; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Cycle check
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }

    return 0;
}