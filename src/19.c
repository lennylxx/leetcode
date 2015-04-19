#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (n == 0) return head;

    struct ListNode *fast, *slow;
    fast = slow = head;

    while (n--) {
        fast = fast->next;
    }

    if (fast == NULL) { /* reach the tail, so we delete the head */
        head = head->next;
        return head;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    /* slow pointer is at the previous node of the one to be deleted */
    slow->next = slow->next->next;

    return head;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *p = l1;
    int i;
    for (i = 1; i <= 4; i++) {
        p->val = i;
        p->next = p + 1;
        p++;
    }
    p->val = 5;
    p->next = NULL;

    p = removeNthFromEnd(l1, 1); /* delete the tail */

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");


    p = removeNthFromEnd(l1, 0); /* delete nothing */

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = removeNthFromEnd(l1, 4); /* delete the head */

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
