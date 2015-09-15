#include <stdio.h>
#include <stdlib.h>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left, *right, *next;
};

void connectHelper(struct TreeLinkNode *node, struct TreeLinkNode *sibling) {
    if (node == NULL) return;
    if (!node->left || !node->right) return;

    /* node have two children */
    node->left->next = node->right;
    node->right->next = (sibling == NULL) ? NULL : sibling->left;

    connectHelper(node->left, node->right);
    connectHelper(node->right, node->right->next);
}

void connect(struct TreeLinkNode *root) {
    if (root == NULL) return;

    root->next = NULL;
    connectHelper(root, NULL);
}

int main() {
    struct TreeLinkNode *root = (struct TreeLinkNode *)calloc(7, sizeof(struct TreeLinkNode));
    root->val = 1;
    root->left = root + 1;
    root->left->val = 2;
    root->right = root + 2;
    root->right->val = 3;

    root->left->left = root + 3;
    root->left->left->val = 4;
    root->left->right = root + 4;
    root->left->right->val = 5;

    root->right->left = root + 5;
    root->right->left->val = 6;
    root->right->right = root + 6;
    root->right->right->val = 7;

    connect(root);

    return 0;
}
