#include <iostream>
#include <queue>
#include <string>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *p;
        string result = to_string(root->val);
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (p->left && p->right) {
                q.push(p->left);
                q.push(p->right);
                result += "," + to_string(p->left->val) + "," + to_string(p->right->val);
            }
            else if (p->left && !p->right) {
                q.push(p->left);
                result += ",L," + to_string(p->left->val);
            }
            else if (!p->left && p->right) {
                q.push(p->right);
                result += ",R," + to_string(p->right->val);
            }
            else {
                result += ",N";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return NULL;
        vector<string> nodes = split(data, ',');
        auto it = nodes.begin();
        TreeNode *root = new TreeNode(stoi(*(it++)));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty() && it != nodes.end()) {
            TreeNode *p = q.front();
            if (*it == "N") {
                it++;
            }
            else if (*it == "L") {
                p->left = new TreeNode(stoi(*(++it)));
                it++;
            }
            else if (*it == "R") {
                p->right = new TreeNode(stoi(*(++it)));
                it++;
            }
            else {
                p->left = new TreeNode(stoi(*(it++)));
                p->right = new TreeNode(stoi(*(it++)));
            }

            q.pop();
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        return root;
    }

    vector<string> split(string str, char delimiter) {
        vector<string> result;
        int last = 0;
        for (int i = 0; i <= str.length(); i++) {
            if (str[i] == delimiter || str[i] == '\0') {
                result.push_back(str.substr(last, i - last));
                last = i + 1;
            }
        }
        return result;
    }
};

bool compareTree(TreeNode *a, TreeNode *b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    return (a->val == b->val)
        && compareTree(a->left, b->left)
        && compareTree(a->right, b->right);
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

     //       1
     //      / \
     //     2   3
     //        / \
     //       4   5
     //      /     \
     //     6       7
     // serialization:  1,2,N,3,4,5,L,6,R,7,N,N

    Codec codec;
    TreeNode *new_root = codec.deserialize(codec.serialize(root));

    assert(compareTree(root, new_root) == true);
    printf("all tests passed!\n");

    return 0;
}
