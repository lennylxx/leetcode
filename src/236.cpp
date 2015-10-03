#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        vector<TreeNode *> path_p;
        vector<TreeNode *> path_q;

        dfs(root, p, path_p);
        dfs(root, q, path_q);

        int minLen = min(path_p.size(), path_q.size());
        TreeNode *lca = NULL;

        for (int i = 0; i < minLen; i++) {
            if (path_p[i] != path_q[i]) {
                break;
            }
            lca = path_p[i];
        }

        return lca;
    }

    bool dfs(TreeNode *root, TreeNode *t, vector<TreeNode *> &path) {
        if (root == NULL || t == NULL) return false;

        if (root == t) {
            path.push_back(root);
            return true;
        }

        path.push_back(root);

        if (dfs(root->left, t, path)) return true;
        if (dfs(root->right, t, path)) return true;

        path.pop_back();

        return false;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    TreeNode *p = root->left;
    TreeNode *q = root->right;

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution s;
    TreeNode *ans = s.lowestCommonAncestor(root, p, q);

    printf("p: %d\nq: %d\n", p->val, q->val);
    if (ans) {
        printf("lca: %d\n", ans->val);
    }
    else {
        printf("lca: NIL\n");
    }

    return 0;
}
