#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        vector<int> t;
        queue<TreeNode *> q;
        if (!root) return ret;
        q.push(root);

        int next = 0; // number of nodes in next level, including NULL nodes
        int cur = 1; // number of nodes in current level, including NULL nodes
        int count = 0; // count of nodes already traversed in current level
        bool flag = 0; // even or odd level
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
                if (flag){ // reverse temp vector if it's even level
                    reverse(t.begin(), t.end());
                }
                flag = !flag;
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
    vector<vector<int> > ret = s.zigzagLevelOrder(root);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j];
        }
        cout << endl;
    }

    return 0;
}
