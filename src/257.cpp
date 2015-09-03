#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        string path = "";
        vector<string> ans;

        dfs(root, ans, path);

        return ans;
    }

    void dfs(TreeNode *root, vector<string> &ans, string path) {
        if (root == NULL) {
            return;
        }

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";

        dfs(root->left, ans, path);
        dfs(root->right, ans, path);
    }
};

int main() {
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = NULL;
    r->left->right = new TreeNode(5);

    Solution s;
    vector<string> paths = s.binaryTreePaths(r);

    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << endl;
    }

    return 0;
}
