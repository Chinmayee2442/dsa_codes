#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node *node;

// Function to create a new node
node createNode(int data) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
node insertn(node root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertn(root->left, data);
    } else if (data > root->data) {
        root->right = insertn(root->right, data);
    }
    return root;
}

// Function to perform postorder traversal and delete a node
node deltn(node root, int key) {
    if (root == NULL) {
        return root;
    }
    root->left = deltn(root->left, key);           //recursively call to delete
    root->right = deltn(root->right, key);
    if (root->data == key) {                       //if root->data is key
        if (root->left == NULL) {
            node temp = root->right;
            //if the left child of the current root is NULL, it means there is no left subtree.
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
        //If the right child of the current root is NULL, it means there is no right subtree.
            node temp = root->left;
            free(root);
            return temp;
        }
        else {
        // If neither the left nor the right child of the current root is NULL, it means the node to be deleted
            node min = root->right;
            while (min->left != NULL) {
                min = min->left;
            }
            root->data = min->data;
            root->right = deltn(root->right, min->data);
        }
    }
    return root;
}

// Function to perform postorder traversal of the binary search tree
void postot(node root) {
    if (root == NULL) {
        return;
    }
    postot(root->left);
    postot(root->right);          //recursively call
    printf("%d ", root->data);
}

int main() {
    node root = NULL;
    int n, i;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    int value;
    for (i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insertn(root, value);
    }

    printf("Binary Search Tree before deletion: ");
    postot(root);

    int del;
    printf("\nEnter the value to delete: ");
    scanf("%d", &del);
    root = deltn(root, del);

    printf("Binary Search Tree after deletion of %d: ", del);
    postot(root);

    return 0;
}
