#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Example tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Leaf nodes = %d\n", countLeafNodes(root));

    return 0;
}