#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int sum) {
    if (root == NULL) {
        return false;
    }
    int remain = sum - root->val;
    
    if (root->left == NULL && root->right == NULL && remain == 0) { /* leaf */
        return true;
    }
    
    if (hasPathSum(root->left, remain) || hasPathSum(root->right, remain)) {
        return true;
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
    struct TreeNode *t = (struct TreeNode *)calloc(4, sizeof(struct TreeNode));
    struct TreeNode *p = t;
    p->val = 1;
    p->left = ++t;
    t->val = -2;
    t->left = t->right = NULL;
    p->right = ++t;
    t->val = 0;
    t->left = t->right = NULL;
    printTreePreOrder(p); printf("\n");

    printf("%d\n", hasPathSum(p, 1)); /* should be true */
    printf("%d\n", hasPathSum(p, 0)); /* should be false */
    printf("%d\n", hasPathSum(p, -1)); /* should be true */

    return 0;
}
