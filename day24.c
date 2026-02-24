#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // If head node contains key
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse to find key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if(temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Key not found.\n");
    }

    return head;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;

    printf("Linked list after deletion:\n");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node* head = createList(n);

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}