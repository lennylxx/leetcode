#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetric0(struct TreeNode* left, struct TreeNode* right){
    if (left == NULL && right == NULL) return true;

    if (left && right
        && (left->val == right->val)
        && isSymmetric0(left->left, right->right)
        && isSymmetric0(left->right, right->left))
        return true;
    else
        return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;

    return isSymmetric0(root->left, root->right);
}

void printTreePreOrder(struct TreeNode* root) {
    if (root) {
        printf("%d", root->val);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
    else
        printf("#");
}

int main() {

    struct TreeNode* r = (struct TreeNode*)calloc(7, sizeof(struct TreeNode));
    struct TreeNode* p = r;

    p->val = 1;
    p->left = r + 1;
    p->right = r + 2;

    p = r + 1;
    p->val = 2;
    p->left = r + 3;
    p->right = r + 4;

    p = r + 2;
    p->val = 2;
    p->left = r + 5;
    p->right = r + 6;

    p = r + 3;
    p->val = 3;

    p = r + 4;
    p->val = 4;

    p = r + 5;
    p->val = 4;

    p = r + 6;
    p->val = 3;

    printTreePreOrder(r); printf("\n");

    /* should be true */
    printf("%d\n", isSymmetric(r));

    return 0;
}
