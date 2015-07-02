#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int searchNode(int inorder[], int inorderSize, int key){
    int i;
    for (i = 0; i < inorderSize; i++) {
        if (key == inorder[i]) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {

    if (preorder == NULL || inorder == NULL
        || preorderSize == 0 || inorderSize == 0) return NULL;

    struct TreeNode *root
        = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];

    int index = searchNode(inorder, inorderSize, preorder[0]);
    if (index == -1) return NULL;

    root->left = buildTree(preorder + 1, index, inorder, index);
    root->right = buildTree(preorder + index + 1, inorderSize - index - 1,
                            inorder + index + 1, inorderSize - index - 1);

    return root;
}

void preOrderPrint(struct TreeNode *root) {
    if (root) {
        printf("%d ", root->val);
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

int main() {

    int pre[] = { 20, 8, 4, 12, 10, 14, 22 };
    int in[] = { 4, 8, 10, 12, 14, 20, 22 };

    struct TreeNode *r
        = buildTree(pre, sizeof(pre)/sizeof(pre[0]), in, sizeof(in)/sizeof(in[0]));

    preOrderPrint(r); printf("\n");

    return 0;
}
