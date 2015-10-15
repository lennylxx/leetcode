#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode *> path;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            path.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ans = -1;
        if (hasNext()) {
            TreeNode *p = path.top();
            path.pop();
            ans = p->val;
            p = p->right;
            while (p) {
                path.push(p);
                p = p->left;
            }
        }
        return ans;
    }
};

int main() {
    /*
     *        5
     *      /   \
     *     2     7
     *    / \   / \
     *   1   4  6  8
     *      /
     *     3
     */

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);

    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
    cout << endl;

    return 0;
}
