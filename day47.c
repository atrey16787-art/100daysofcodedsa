#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build tree from array (level order)
struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) {
        return NULL;
    }

    struct TreeNode* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Height function
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    int n;

    // INPUT
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements in level order (-1 for NULL):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build tree
    struct TreeNode* root = buildTree(arr, n, 0);

    // OUTPUT
    printf("Height of Binary Tree = %d\n", height(root));

    return 0;
}