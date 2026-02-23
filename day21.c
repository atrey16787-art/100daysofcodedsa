#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if(head == NULL) {
            head = newNode;  // first node
            tail = newNode;
        } else {
            tail->next = newNode;  // attach at end
            tail = newNode;
        }
    }

    // Traverse and print the linked list
    struct Node* temp = head;
    printf("Linked list elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}