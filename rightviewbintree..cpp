#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

void printRightView(struct Node* root, int level, int* maxLevel) {
    if (root == NULL) return;

    if (*maxLevel < level) {
        printf("%d\t", root->data);
        *maxLevel = level;
    }

    printRightView(root->right, level + 1, maxLevel);
    printRightView(root->left, level + 1, maxLevel);
}

void rightView(struct Node* root) {
    int maxLevel = 0;
    printRightView(root, 1, &maxLevel);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->right = createNode(8);

    rightView(root);

    return 0;
}
