#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flattenHelper(struct TreeNode* root, struct TreeNode **start, struct TreeNode **end){
    if (root == NULL) {
        *start = *end = NULL;
        return;
    }
    struct TreeNode *lstart, *lend, *rstart, *rend;
    lstart = lend = rstart = rend = NULL;

    flattenHelper(root->left, &lstart, &lend);
    flattenHelper(root->right, &rstart, &rend);

    root->left = NULL;

    if (lend != NULL) {
        root->right = lstart;
        lend->right = rstart;
    }
    else {
        root->right = rstart;
    }

    *start = root;

    if (rend != NULL) {
        *end = rend;
    }
    else if (lend != NULL) {
        *end = lend;
    }
    else {
        *end = root;
    }
}

void flatten(struct TreeNode* root) {
    struct TreeNode *start, *end;
    start = end = NULL;

    flattenHelper(root, &start, &end);
}

int main() {
    struct TreeNode *root = (struct TreeNode *)calloc(3, sizeof(struct TreeNode));
    root->val = 1;
    root->left = root + 1;
    root->left->val = 2;
    root->left->left = root + 2;
    root->left->left->val = 3;

    flatten(root);

    while (root) {
        assert(root->left == NULL);
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");

    return 0;
}
