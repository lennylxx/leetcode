#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *p1 = l1, *p2 = l2;

        ListNode *ans = new ListNode(0);
        ListNode *p = ans, *last = NULL, *t = NULL;

        int sum = 0;
        while (1) {
            if (p1 && p2) {
                sum += p1->val + p2->val;
            }
            else if (p1 && p2 == NULL) {
                sum += p1->val;
            }
            else if (p2 && p1 == NULL) {
                sum += p2->val;
            }
            else {
                break;
            }

            p->val = sum % 10;
            sum /= 10;

            p->next = t = new ListNode(0); // for next node or the final node
            last = p;
            p = p->next;

            if (p1) { p1 = p1->next; }
            if (p2) { p2 = p2->next; }
        }

        if (sum != 0) {
            t->val = sum;
        }
        else {
            delete t; // sum is 0, we don't need a redundant 0, delete it 
            last->next = NULL;
        }

        return ans;
    }
};

int main() {
    ListNode *l1 = new ListNode(2);
    ListNode *p1 = l1;
    p1->next = new ListNode(4);
    p1 = p1->next;
    p1->next = new ListNode(5);

    ListNode *l2 = new ListNode(5);
    ListNode *p2 = l2;
    p2->next = new ListNode(6);
    p2 = p2->next;
    p2->next = new ListNode(4);

    p2 = p2->next;
    p2->next = new ListNode(9);
    p2 = p2->next;
    p2->next = new ListNode(9);

    Solution s;
    ListNode *ans = s.addTwoNumbers(l1, l2);
    ListNode *p = ans;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
