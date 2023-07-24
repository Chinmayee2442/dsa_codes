#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isThreaded; // Flag indicating whether the right pointer is a thread or not
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Function to insert a node in the threaded binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
        // Set the right pointer as a thread when the left subtree is empty
        if (root->left->right == NULL) {
            root->left->right = root;
            root->left->isThreaded = 1;
        }
    } else if (data > root->data) {
        // If the right child is a thread, insert the new node as the right child
        if (root->isThreaded) {
            struct Node* newNode = createNode(data);
            newNode->right = root->right;
            newNode->isThreaded = 1;
            root->right = newNode;
            root->isThreaded = 0;
        } else {
            // Otherwise, recursively insert into the right subtree
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Function to perform inorder traversal of the threaded binary tree
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* current = root;
    // Find the leftmost node in the subtree
    while (current->left != NULL) {
        current = current->left;
    }

    // Traverse the threaded binary tree using right pointers
    while (current != NULL) {
        printf("%d ", current->data);

        if (current->isThreaded) {
            current = current->right;
        } else {
            current = current->right;
            // Find the leftmost node in the right subtree
            while (current != NULL && current->left != NULL) {
                current = current->left;
            }
        }
    }
}

// Function to create and convert a binary tree to a threaded binary tree
struct Node* createAndConvert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    insertNode(root, data);
    return root;
}

int main() {
    struct Node* root = NULL;

    int numValues;
    printf("Enter the number of values for the binary tree: ");
    scanf("%d", &numValues);

    int value;
    for (int i = 0; i < numValues; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = createAndConvert(root, value);
    }


    printf("Inorder Traversal of Threaded Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
