#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        vector<int> t;
        queue<TreeNode *> q;
        if (!root) return ret;
        q.push(root);

        int next = 0; // number of nodes in next level (include NULL nodes)
        int cur = 1; // number of nodes in current level (include NULL nodes)
        int count = 0; // count of nodes already traversed in current level
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();

            if (p){// push children into queue if parent is not NULL
                t.push_back(p->val);
                q.push(p->left);
                q.push(p->right);
                next += 2;
            }

            count++;
            if (count == cur && !t.empty()) {
                ret.push_back(t);
                t.clear();
                cur = next;
                count = next = 0;
            }
        }

        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *p = root;
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p = p->right;
    p->left = new TreeNode(4);
    p = p->left;
    p->right = new TreeNode(5);
    p = p->right;
    p->left = new TreeNode(6);
    p->right = new TreeNode(7);

    Solution s;
    vector<vector<int> > ret = s.levelOrder(root);
    
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
