#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/** Modification of Morris in-order tree traversal */
int kthSmallest0(struct TreeNode* root, int k) {
    if (root == NULL || k == 0) return -1;

    struct TreeNode *cur = root;
    struct TreeNode **p = NULL;
    int i = 0;
    int ans = -1;

    while (cur != NULL) {
        if (cur->left != NULL) {
            /* find predecessor node */
            p = &(cur->left);
            while (1) {
                if (*p == NULL) {
                    if (i >= k) cur = cur->right; /* get to rightest node asap */
                    else {
                        *p = cur;
                        cur = cur->left;
                    }
                    break;
                }

                if (*p == cur) {
                    if (++i == k) ans = cur->val; /* can't just return, have to recover tree   */
                    *p = NULL;                    /* time complexity changes from O(k) to O(n) */
                    cur = cur->right;
                    break;
                }
                p = &((*p)->right);
            }
        }
        else {
            if (++i == k) ans = cur->val;
            cur = cur->right;
        }
    }

    return ans;
}

/** Divide and conquer, just like quick sort */
int getCount(struct TreeNode* root) {
    if (root == NULL) return 0;
    return getCount(root->left) + getCount(root->right) + 1;
}

int kthSmallest1(struct TreeNode* root, int k) {
    if (root == NULL || k == 0) return -1;

    int l = getCount(root->left); /* it takes O(n) */
    if (l == k - 1) return root->val;
    if (l < k)
        return kthSmallest1(root->right, k - l - 1);
    else
        return kthSmallest1(root->left, k);
}

/** In-order traversal */
int findHelper(struct TreeNode* root, int* k) {
    if (root == NULL || *k == 0) return -1;

    int x = findHelper(root->left, k);
    if (*k == 0) return x;
    (*k)--;
    if (*k == 0) return root->val;
    return findHelper(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k) {
    return findHelper(root, &k);
}

int main() {
    struct TreeNode *r = (struct TreeNode *)calloc(9, sizeof(struct TreeNode));
    struct TreeNode *p = r;

    p->val = 6;
    p->left = r + 1;
    p->right = r + 2;

    p = p->left;
    p->val = 2;
    p->left = r + 3;
    p->right = r + 4;

    p = p->left;
    p->val = 1;

    p = r + 4;
    p->val = 4;
    p->left = r + 5;
    p->right = r + 6;

    p = r + 5;
    p->val = 3;

    p = r + 6;
    p->val = 5;

    p = r + 2;
    p->val = 7;
    p->right = r + 7;

    p = p->right;
    p->val = 9;
    p->left = r + 8;

    p = p->left;
    p->val = 8;

    int i;
    for (i = 1; i <= 9; i++) {
        printf("%d\n", kthSmallest(r, i));
    }
    return 0;
}
