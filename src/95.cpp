#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode *> > d(n + 1);

        d[0].push_back(NULL); // d[0][0]
        if (n == 0) return d[0];

        d[1].push_back(new TreeNode(1)); // d[1][0]

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                for (int ii = 0; ii < d[j - 1].size(); ii++) {
                    for (int jj = 0; jj < d[i - j].size(); jj++){
                        TreeNode *root = new TreeNode(j);
                        /* left child tree can be found in memorization */
                        root->left = d[j - 1][ii];

                        /* nodes of right child tree is bigger than root, but we
                           can add root's value to all nodes in memorization to 
                           build the correct tree */
                        root->right = addNodes(d[i - j][jj], j);
                        d[i].push_back(root); // d[i][ii * jj]
                    }
                }
            }
        }

        return d[n];
    }

    TreeNode * addNodes(TreeNode *root, int x) {
        if (!root) return NULL;
        TreeNode *p = new TreeNode(root->val + x);
        p->left = addNodes(root->left, x);
        p->right = addNodes(root->right, x);
        return p;
    }

    void printTreeLevelOrder(TreeNode *root) {
        string buf;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (p) {
                buf.push_back(p->val + '0');
                if (p->left || p->right){
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            else
                buf.push_back('#');
        }
        cout << buf << endl;
    }
};

int main() {
    Solution s;
    vector<TreeNode *> ret = s.generateTrees(4);

    for (int i = 0; i < ret.size(); i++) {
        s.printTreeLevelOrder(ret[i]);
    }

    return 0;
}
