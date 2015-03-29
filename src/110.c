#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isBalanced(struct TreeNode *root) {
    if (root == NULL)
        return true;
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    int d = l - r;
    if (d == 0 || d == 1 || d == -1) {
        if (isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        else return false;
    }
    else return false;
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
    struct TreeNode *t = (struct TreeNode *)calloc(7, sizeof(struct TreeNode));
    struct TreeNode *p = t;
    p->val = 1;
    
    p->left = ++t;
    t->val = 2;
    p->left->left = ++t;
    p->left->right = NULL;
    t->val = 3;
    p->left->left->left = ++t;
    p->left->left->right = NULL;
    t->val = 4;
    t->left = t->right = NULL;
    
    p->right = ++t;
    t->val = 2;
    p->right->left = NULL;
    p->right->right = ++t;
    t->val = 3;
    p->right->right->left = NULL;
    p->right->right->right = ++t;
    t->val = 4;
    t->left = t->right = NULL;

    printTreePreOrder(p); printf("\n");

    printf("%d\n", isBalanced(p)); /* should be false */
    printf("%d\n", isBalanced(p->left)); /* should be false */
    printf("%d\n", isBalanced(p->left->left)); /* should be true */
    printf("%d\n", isBalanced(NULL)); /* should be true */

    return 0;
}
