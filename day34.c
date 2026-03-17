#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure (stack)
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = *top;
    *top = temp;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) {
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        // If operator
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            int result;
            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}