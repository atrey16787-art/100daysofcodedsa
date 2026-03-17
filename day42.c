#include <stdio.h>
#include <stdlib.h>

/*********** STACK ***********/
typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int n) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = n;
    s->top = -1;
    s->arr = (int*)malloc(n * sizeof(int));
    return s;
}

void push(Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(Stack* s) {
    return s->arr[s->top--];
}

int isEmptyStack(Stack* s) {
    return s->top == -1;
}

/*********** QUEUE ***********/
typedef struct {
    int *arr;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = n;
    q->front = 0;
    q->size = 0;
    q->rear = n - 1;
    q->arr = (int*)malloc(n * sizeof(int));
    return q;
}

void enqueue(Queue* q, int x) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(Queue* q) {
    int x = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
}

int isEmptyQueue(Queue* q) {
    return q->size == 0;
}

/*********** REVERSE QUEUE ***********/
void reverseQueue(Queue* q) {
    Stack* s = createStack(q->capacity);

    // Step 1: Dequeue all elements → push to stack
    while (!isEmptyQueue(q)) {
        push(s, dequeue(q));
    }

    // Step 2: Pop from stack → enqueue back
    while (!isEmptyStack(s)) {
        enqueue(q, pop(s));
    }
}

/*********** MAIN ***********/
int main() {
    int N;
    scanf("%d", &N);

    Queue* q = createQueue(N);

    int x;
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    reverseQueue(q);

    // Print reversed queue
    while (!isEmptyQueue(q)) {
        printf("%d ", dequeue(q));
    }

    return 0;
}