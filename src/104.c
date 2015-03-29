#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}

void printTreePreOrder(struct TreeNode *p) {
    if (p != NULL) {
        printf("%d", p->val);
        printTreePreOrder(p->left);
        printTreePreOrder(p->right);
    }
    else printf("#");
}

int main() {
    struct TreeNode *t = (struct TreeNode *)calloc(4, sizeof(struct TreeNode));
    struct TreeNode *p = t;
    p->val = 1;
    p->left = ++t;
    t->val = 2;
    t->left = t->right = NULL;
    p->right = ++t;
    t->val = 3;
    p->right->left = NULL;
    p->right->right = ++t;
    t->val = 4;
    t->left = t->right = NULL;
    printTreePreOrder(p); printf("\n");

    printf("%d\n", maxDepth(p));

    return 0;
}
