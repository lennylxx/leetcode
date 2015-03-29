#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();

            if (p) {
                ret.push_back(p->val);
                s.push(p->right);
                s.push(p->left);
            }
        }
        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    TreeNode *p = root;

    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p = p->left;
    p->left = new TreeNode(1);
    p->right = new TreeNode(3);

    Solution s;
    vector<int> ret = s.preorderTraversal(root);

    // should be 42135
    for (unsigned int i = 0; i < ret.size(); i++) {
        cout << ret[i];
    }
    cout << endl;

    return 0;
}
