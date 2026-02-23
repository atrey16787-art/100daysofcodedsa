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

// Function to append a node at the end of list
void appendNode(struct Node** headRef, struct Node** tailRef, int value) {
    struct Node* newNode = createNode(value);
    if(*headRef == NULL) {
        *headRef = newNode;
        *tailRef = newNode;
    } else {
        (*tailRef)->next = newNode;
        *tailRef = newNode;
    }
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;  // temporary dummy node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // append remaining nodes
    if(l1 != NULL) tail->next = l1;
    if(l2 != NULL) tail->next = l2;

    return dummy.next;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m;

    // Input first list
    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    printf("Enter %d integers for first list:\n", n);
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        appendNode(&head1, &tail1, value);
    }

    // Input second list
    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    printf("Enter %d integers for second list:\n", m);
    for(int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        appendNode(&head2, &tail2, value);
    }

    // Merge lists
    struct Node* merged = mergeLists(head1, head2);

    // Print merged list
    printf("Merged linked list: ");
    printList(merged);

    return 0;
}