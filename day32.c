#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop
void pop() {
    if (top == -1) {
        return; // no output needed here
    }
    top--;
}

// Display
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    int m;
    scanf("%d", &m);

    // Pop m elements
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}