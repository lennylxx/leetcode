#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void sumNumbersHelper(struct TreeNode* root, int* sum, int num) {
    if (root == NULL) return;

    num = num * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        *sum += num;
        return;
    }

    sumNumbersHelper(root->left, sum, num);
    sumNumbersHelper(root->right, sum, num);
}

int sumNumbers(struct TreeNode* root) {
    if (root == NULL) return 0;

    int sum = 0, num = 0;
    sumNumbersHelper(root, &sum, num);

    return sum;
}

int main() {
    struct TreeNode* root = (struct TreeNode *)calloc(3, sizeof(struct TreeNode));
    root->val = 1;
    root->left = root + 1;
    root->left->val = 2;
    root->right = root + 2;
    root->right->val = 3;

    /* should be 25 */
    printf("%d\n", sumNumbers(root));

    return 0;
}
