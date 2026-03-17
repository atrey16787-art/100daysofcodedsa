#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

// Enqueue
void enqueue(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

// Dequeue
void dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }
    front = (front + 1) % MAX;
    size--;
}

// Display (circular order)
void display() {
    int count = size;
    int i = front;

    while (count--) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    int m;
    scanf("%d", &m);

    // Dequeue m times
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}