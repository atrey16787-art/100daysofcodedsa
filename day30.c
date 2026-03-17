#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coef;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int coef, int exp) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

// Insert at end
struct Node* insert(struct Node* head, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coef);
        else if (temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int coef, exp;
        scanf("%d %d", &coef, &exp);
        head = insert(head, coef, exp);
    }

    printPolynomial(head);

    return 0;
}