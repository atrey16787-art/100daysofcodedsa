#include <stdio.h>
#include <stdlib.h>

/*********** TREE NODE ***********/
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

/*********** CREATE NODE ***********/
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

/*********** QUEUE (for level-order building) ***********/
typedef struct {
    Node** arr;
    int front, rear;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(n * sizeof(Node*));
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(Queue* q, Node* node) {
    q->arr[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

/*********** BUILD TREE ***********/
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Queue* q = createQueue(n);

    Node* root = newNode(arr[0]);
    enqueue(q, root);

    int i = 1;

    while (!isEmpty(q) && i < n) {
        Node* curr = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

/*********** INORDER ***********/
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/*********** MAIN ***********/
int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, N);

    inorder(root);

    return 0;
}