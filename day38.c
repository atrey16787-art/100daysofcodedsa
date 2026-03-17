#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return front == -1;
}

// Check full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// push_front
void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// pop_back
void pop_back() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// front element
void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// back element
void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// size
void getSize() {
    if (isEmpty()) {
        printf("0\n");
        return;
    }

    if (rear >= front)
        printf("%d\n", rear - front + 1);
    else
        printf("%d\n", MAX - front + rear + 1);
}

// display
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int op, x;

        scanf("%d", &op);

        switch (op) {
            case 1: // push_front
                scanf("%d", &x);
                push_front(x);
                break;
            case 2: // push_back
                scanf("%d", &x);
                push_back(x);
                break;
            case 3: // pop_front
                pop_front();
                break;
            case 4: // pop_back
                pop_back();
                break;
            case 5: // front
                getFront();
                break;
            case 6: // back
                getBack();
                break;
            case 7: // size
                getSize();
                break;
            case 8: // display
                display();
                break;
        }
    }

    return 0;
}