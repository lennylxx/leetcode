#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) break;
    }

    if (fast == NULL || fast->next == NULL) return NULL;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *p = l1;
    p->val = 1;
    p->next = l1 + 1;
    p = p->next;

    p->val = 2;
    p->next = l1 + 2;
    p = p->next;

    p->val = 3;
    p->next = l1 + 3;
    p = p->next;

    p->val = 4;
    p->next = l1 + 4;
    p = p->next;

    p->val = 5;
    p->next = l1 + 2; /* cycle to 3 */

    struct ListNode *node = detectCycle(l1);

    if (node) {
        printf("%d\n", node->val);
    }
    else {
        printf("NIL\n");
    }

    return 0;
}
