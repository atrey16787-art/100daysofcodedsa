#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Queue implementation
int queue[MAX];
int front = 0, rear = 0;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Enqueue
void enqueue(int x) {
    queue[rear++] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// BFS function
void BFS(int s) {
    enqueue(s);
    visited[s] = 1;

    while (front < rear) {
        int node = dequeue();
        printf("%d ", node);

        struct Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->vertex;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(s);

    return 0;
}