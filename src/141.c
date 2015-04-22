#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (fast && slow) {
        if (fast) fast = fast->next;
        if (fast) fast = fast->next;

        if (slow) slow = slow->next;

        if (fast == slow && slow != NULL) return true;
    }

    return false;
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
    p->next = NULL; /* no cycle */

    printf("%d\n", hasCycle(l1));

    /* no cycle */
    printf("%d\n", hasCycle(l1 + 4));

    p->next = l1 + 2; /* cycle */
    printf("%d\n", hasCycle(l1));

    /* no cycle */
    printf("%d\n", hasCycle(NULL));

    return 0;
}
