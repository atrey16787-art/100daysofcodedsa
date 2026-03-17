#include <stdio.h>
#include <stdlib.h>

/*********** NODE ***********/
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*********** QUEUE ***********/
typedef struct {
    Node* front;
    Node* rear;
} Queue;

/*********** CREATE QUEUE ***********/
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

/*********** ENQUEUE ***********/
void enqueue(Queue* q, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    // If queue is empty
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

/*********** DEQUEUE ***********/
int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;

    Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

/*********** MAIN ***********/
int main() {
    int N;
    scanf("%d", &N);

    Queue* q = createQueue();
    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') { // enqueue
            scanf("%d", &x);
            enqueue(q, x);
        } 
        else if (op[0] == 'd') { // dequeue
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}