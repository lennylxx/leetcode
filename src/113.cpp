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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;

        vector<int> path;
        pathSumHelper(root, sum, ans, path);

        return ans;
    }

    void pathSumHelper(TreeNode *root, int sum, vector<vector<int> > &ans, vector<int> &path) {
        if (root == NULL) {
            return;
        }
        if (sum == root->val && root->left == NULL && root->right == NULL) {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        pathSumHelper(root->left, sum - root->val, ans, path);
        pathSumHelper(root->right, sum - root->val, ans, path);
        path.pop_back();
    }
};

int main() {
    int sum = 22;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    auto ans = s.pathSum(root, sum);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
