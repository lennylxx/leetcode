#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *fast, *slow, *prev;
        fast = slow = head;
        prev = NULL;
        while (fast) {
            fast = fast->next;
            if (!fast) break;
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (slow == NULL) return NULL;
        if (prev) prev->next = NULL;

        TreeNode *node = new TreeNode(slow->val);
        node->left = sortedListToBST(slow == head ? NULL : head);
        node->right = sortedListToBST(slow->next);

        return node;
    }

    void preOrderTraversal(TreeNode *root) {
        if (root == NULL) return;

        printf("%d ", root->val);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
};

int main() {

    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i = 2; i <= 7; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    p->next = NULL;

    p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    Solution s;
    TreeNode *root = s.sortedListToBST(head);

    s.preOrderTraversal(root);
    printf("\n");

    return 0;
}
