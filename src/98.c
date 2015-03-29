#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minValue(struct TreeNode *root) {
    int l, r;
    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }
    else if (root->left && root->right == NULL) {
        l = minValue(root->left);
        return l < root->val ? l : root->val;
    }
    else if (root->right && root->left == NULL) {
        r = minValue(root->right);
        return r < root->val ? r : root->val;
    }
    else {
        l = minValue(root->left);
        r = minValue(root->right);
        return l < r ? l : r;
    }
}

int maxValue(struct TreeNode *root) {
    int l, r;
    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }
    else if (root->left && root->right == NULL) {
        l = maxValue(root->left);
        return l > root->val ? l : root->val;
    }
    else if (root->right && root->left == NULL) {
        r = maxValue(root->right);
        return r > root->val ? r : root->val;
    }
    else {
        l = maxValue(root->left);
        r = maxValue(root->right);
        return l > r ? l : r;
    }
}

bool isValidBST(struct TreeNode *root) {
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    else if (root->left && root->right == NULL) {
        if (root->left->val < root->val
            && maxValue(root->left) < root->val
            && isValidBST(root->left))
            return true;
        else return false;
    }
    else if (root->right && root->left == NULL) {
        if (root->right->val > root->val
            && minValue(root->right) > root->val
            && isValidBST(root->right))
            return true;
        else return false;
    }
    else {
        if (root->left->val < root->val
            && root->right->val > root->val
            && maxValue(root->left) < root->val
            && minValue(root->right) > root->val
            && isValidBST(root->left)
            && isValidBST(root->right)) {
            return true;
        }
        else return false;
    }
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
    struct TreeNode *t = (struct TreeNode *)calloc(6, sizeof(struct TreeNode));
    struct TreeNode *p = t;

    p->val = 4;

    p->left = ++t;
    t->val = 2;
    p->left->left = ++t;
    t->val = 1;
    t->left = t->right = NULL;
    p->left->right = ++t;
    t->val = 3;
    t->left = t->right = NULL;

    p->right = ++t;
    t->val = 5;
    t->left = t->right = NULL;

    printTreePreOrder(p); printf("\n");

    printf("%d\n", isValidBST(p)); /* should be true*/

    p->right->left = ++t;
    t->val = 2;
    t->left = t->right = NULL;

    printTreePreOrder(p); printf("\n");

    printf("%d\n", isValidBST(p)); /* should be false*/
    
    return 0;
}
