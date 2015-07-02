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

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {

    if (inorder == NULL || postorder == NULL
        || inorderSize == 0 || postorderSize == 0) return NULL;

    struct TreeNode *root
        = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];

    int index = searchNode(inorder, inorderSize, postorder[postorderSize - 1]);
    if (index == -1) return NULL;

    root->left = buildTree(inorder, index, postorder, index);
    root->right = buildTree(inorder + index + 1, inorderSize - index - 1,
                            postorder + index, inorderSize - index - 1);

    return root;
}

void postOrderPrint(struct TreeNode *root) {
    if (root) {
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        printf("%d ", root->val);
    }
}

int main() {

    int in[] = { 4, 8, 10, 12, 14, 20, 22 };
    int post[] = { 4, 10, 14, 12, 8, 22, 20 };

    struct TreeNode *r
        = buildTree(in, sizeof(in)/sizeof(in[0]), post, sizeof(post)/sizeof(post[0]));

    postOrderPrint(r); printf("\n");

    return 0;
}
