#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;

    if (p == NULL) return q;
    if (q == NULL) return p;

    struct TreeNode *i, *j, *lca;
    i = j = lca = root;

    while (i || j) {
        if (i->val > p->val) {
            i = i->left;
        }
        else if (i->val < p->val) {
            i = i->right;
        }
        else {
            lca = i;
            break;
        }

        if (j->val > q->val) {
            j = j->left;
        }
        else if (j->val < q->val) {
            j = j->right;
        }
        else {
            lca = j;
            break;
        }


        if (i->val != j->val) {
            break;
        }
        lca = i;
    }

    return lca;
}

int main() {

    struct TreeNode *r = (struct TreeNode *)calloc(9, sizeof(struct TreeNode));
    struct TreeNode *t = r;
    struct TreeNode *p = NULL, *q = NULL;

    t->val = 6;
    t->left = r + 1;
    t->right = r + 2;

    t = t->left;
    t->val = 2;
    t->left = r + 3;
    t->right = r + 4;
    t->left->val = 0;

    t = r + 4;
    t->val = 4;
    t->left = r + 5;
    t->right = r + 6;
    t->left->val = 3;
    t->right->val = 5;

    t = r->right;
    t->val = 8;
    t->left = r + 7;
    t->right = r + 8;
    t->left->val = 7;
    t->right->val = 9;

    p = r + 1; /* 2 */
    q = r + 2; /* 8 */

    struct TreeNode *lca = lowestCommonAncestor(r, p, q);

    printf("lca of %d and %d is: %d\n", p->val, q->val, lca->val);

    p = r + 1; /* 2 */
    q = r + 4; /* 4 */

    lca = lowestCommonAncestor(r, p, q);

    printf("lca of %d and %d is: %d\n", p->val, q->val, lca->val);

    return 0;
}
