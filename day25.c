#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    
    // Create linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    printf("Enter key to count: ");
    scanf("%d", &key);
    
    // Count occurrences
    int count = 0;
    temp = head;
    
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    
    printf("Number of occurrences: %d\n", count);
    
    return 0;
}