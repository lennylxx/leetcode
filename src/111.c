#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    
    int l = minDepth(root->left);
    int r = minDepth(root->right);   
    
    if (l == 0 && r == 0) { /* leaf */
        return 1;
    }
    else if (l && r == 0) { /* no right child */
        return l + 1;
    }
    else if (r && l == 0) { /* no left child */
        return r + 1;
    }
    else {
        return l < r ? (l + 1) : (r + 1);
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
    struct TreeNode *t = (struct TreeNode *)calloc(4, sizeof(struct TreeNode));
    struct TreeNode *p = t;
    p->val = 1;
    p->right = ++t;
    t->val = 2;
    t->right = NULL;
    p->right->left = ++t;
    t->val = 3;
    t->left = NULL;
    p->right->left->right = ++t;
    t->val = 4;
    t->left = t->right = NULL;
    printTreePreOrder(p); printf("\n");

    /* should be 4 */
    printf("%d\n", minDepth(p));

    return 0;
}
