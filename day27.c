#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
        
    temp->next = newNode;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    int diff = abs(len1 - len2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    
    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }
    
    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data)
            return ptr1;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return NULL;
}

int main() {
    int n, m, x;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    
    // Input first list
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    
    printf("Enter elements of first list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head1, x);
    }
    
    // Input second list
    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    
    printf("Enter elements of second list: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        insertEnd(&head2, x);
    }
    
    struct Node* intersection = getIntersection(head1, head2);
    
    if (intersection)
        printf("Intersection Point: %d\n", intersection->data);
    else
        printf("No Intersection\n");
        
    return 0;
}