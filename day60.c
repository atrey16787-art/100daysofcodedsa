#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order (no -1 here)
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct TreeNode* root = newNode(arr[0]);

    struct TreeNode* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i++]);
            queue[rear++] = curr->left;
        }

        if (i < n) {
            curr->right = newNode(arr[i++]);
            queue[rear++] = curr->right;
        }
    }

    return root;
}

// Check Min-Heap
int isMinHeap(struct TreeNode* root) {
    if (!root) return 1;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int nullSeen = 0;

    while (front < rear) {
        struct TreeNode* node = queue[front++];

        // Left child
        if (node->left) {
            if (nullSeen || node->val > node->left->val)
                return 0;
            queue[rear++] = node->left;
        } else {
            nullSeen = 1;
        }

        // Right child
        if (node->right) {
            if (nullSeen || node->val > node->right->val)
                return 0;
            queue[rear++] = node->right;
        } else {
            nullSeen = 1;
        }
    }

    return 1;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}