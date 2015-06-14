#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode *l = root->left;
    struct TreeNode *r = root->right;

    int most_left_height = 1;
    int most_right_height = 1;

    while (l != NULL) {
        l = l->left;
        most_left_height++;
    }

    while (r != NULL) {
        r = r->right;
        most_right_height++;
    }

    if (most_left_height == most_right_height) { /* it's a full binary tree */
        return (1 << most_left_height) - 1;
    }
    else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int main() {

    struct TreeNode *r = (struct TreeNode *)calloc(9, sizeof(struct TreeNode));
    struct TreeNode *p = r;

    int i;
    for (i = 1; i <= 9; i++) {
        p->val = i;
        p++;
    }

    p = r;
    p->left = r + 1;
    p->right = r + 2;

    p = r + 1;
    p->left = r + 3;
    p->right = r + 4;

    p = r + 2;
    p->left = r + 5;
    p->right = r + 6;

    p = r + 3;
    p->left = r + 7;
    p->right = r + 8;

    /* should be 9 */
    printf("%d\n", countNodes(r));

    return 0;
}
