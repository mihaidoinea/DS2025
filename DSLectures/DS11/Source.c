#include <stdio.h>
#include <stdlib.h>

#define MIN_SPACING 15  

typedef struct Node {
    int time;
    struct Node* left, * right;
} Node;


Node* createNode(int time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->time = time;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int insert(Node** root, int time) {
    Node* current = *root, * parent = NULL;
    Node* pred = NULL, * succ = NULL;

    while (current != NULL) {
        parent = current;
        if (time < current->time) {
            succ = current;
            current = current->left;
        }
        else if (time > current->time) {
            pred = current;
            current = current->right;
        }
        else {
            return 0;
        }
    }

    if ((pred && time - pred->time < MIN_SPACING) ||
        (succ && succ->time - time < MIN_SPACING)) {
        return 0;
    }

    Node* newNode = createNode(time);
    if (parent == NULL) {
        *root = newNode;
    }
    else if (time < parent->time) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    return 1;
}

void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("Plane landing at time: %d\n", root->time);
    printInOrder(root->right);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int NextAvailableTime(Node* root, int time) {
    Node* current = root;
    Node* pred = NULL, * succ = NULL;

    while (current != NULL) {
        if (time < current->time) {
            succ = current;
            current = current->left;
        }
        else if (time > current->time) {
            pred = current;
            current = current->right;
        }
        else {
            pred = succ = current;
            break;
        }
    }

    int earliest = time;
    if (pred && earliest - pred->time < MIN_SPACING)
        earliest = pred->time + MIN_SPACING;
    if (succ && succ->time - earliest < MIN_SPACING)
        earliest = succ->time - MIN_SPACING;

    while (1) {
        current = root;
        pred = succ = NULL;

        while (current != NULL) {
            if (earliest < current->time) {
                succ = current;
                current = current->left;
            }
            else if (earliest > current->time) {
                pred = current;
                current = current->right;
            }
            else {
                earliest++;
                continue;
            }
        }

        int ok = 1;
        if ((pred && earliest - pred->time < MIN_SPACING) ||
            (succ && succ->time - earliest < MIN_SPACING))
            ok = 0;

        if (ok) break;
        earliest++;
    }

    return earliest;
}




int main() {
    Node* root = NULL;
    int landings[] = { 100, 90, 115, 80, 130, 120, 250, 240 };
    int n = sizeof(landings) / sizeof(landings[0]);

    for (int i = 0; i < n; i++) {
        if (insert(&root, landings[i])) {
            printf("Landing time %d scheduled.\n", landings[i]);
        }
        else {
            printf("Landing time %d rejected (spacing conflict).\n", landings[i]);
        }
    }

    printf("\nFinal landing schedule:\n");
    printInOrder(root);


    int suggestedTime = NextAvailableTime(root, 255);
    printf("Next available landing time: %d\n", suggestedTime);

    freeTree(root);
    return 0;
}