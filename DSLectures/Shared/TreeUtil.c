#include "Shared.h"

// Function to create a new node
TreeNode* createNode(Student* stud) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode != NULL)
    {
        newNode->data = stud;
        newNode->parent = NULL;
        newNode->children = NULL;
        newNode->noDescendants = 0;
    }
    return newNode;
}

void insertChild(TreeNode* root, int parentKey, Student* data) {
    // If the root is NULL, return
    if (root == NULL) return;

    // If the current node matches the parentKey, insert the child
    if (root->data->reference.extRef == parentKey) {
        TreeNode** oldItems = NULL;
        // Allocate space for one more child
        root->children = (TreeNode**)realloc(oldItems = root->children, (root->noDescendants + 1) * sizeof(TreeNode*));

        if (root->children != NULL)
        {
            // Create a new child node
            TreeNode* newChild = createNode(data);
            newChild->parent = root;

            // Add the new child node to the parent's children list
            root->children[root->noDescendants] = newChild;
            root->noDescendants++;
            return;
        }
    }

    // Otherwise, recursively search through the children of the current node
    for (int i = 0; i < root->noDescendants; i++) {
        insertChild(root->children[i], parentKey, data);
    }
}

// Function to print the tree (for debugging purposes)
void printTree(TreeNode* root, int level) {
    if (root == NULL) return;

    // Print the current node's data
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printStudent(root->data);

    // Recursively print each child
    for (int i = 0; i < root->noDescendants; i++) {
        printTree(root->children[i], level + 1);
    }
}
