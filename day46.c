#include <stdio.h>
#include <stdlib.h>

/*********** NODE ***********/
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

/*********** QUEUE ***********/
typedef struct {
    Node** arr;
    int front, rear;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(n * sizeof(Node*));
    q->front = q->rear = 0;
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

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

/*********** LEVEL ORDER ***********/
void levelOrder(Node* root) {
    if (root == NULL)
        return;

    Queue* q = createQueue(1000);
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* curr = dequeue(q);

        printf("%d ", curr->data);

        if (curr->left)
            enqueue(q, curr->left);

        if (curr->right)
            enqueue(q, curr->right);
    }
}

/*********** MAIN ***********/
int main() {
    int N;

    printf("Enter number of nodes: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter level order values (-1 for NULL): ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}