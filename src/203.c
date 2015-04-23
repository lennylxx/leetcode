#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *ret;
    struct ListNode *prev, *p;

    ret = p = head;
    prev = head;

    while (p) {
        if (p->val == val) {
            if (p == ret) { /* head */
                ret = p->next;
                prev = ret; /* maybe useless */
            }
            else { /* NOT head */
                prev->next = p->next;
            }
        }
        else {
            prev = p;
        }
        p = p->next;
    }

    return ret;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)calloc(9, sizeof(struct ListNode));
    struct ListNode *p = l1;
    
    p->val = 6;
    p->next = l1 + 1;
    p = p->next;

    p->val = 6;
    p->next = l1 + 2;
    p = p->next;

    p->val = 1;
    p->next = l1 + 3;
    p = p->next;

    p->val = 6;
    p->next = l1 + 4;
    p = p->next;

    p->val = 6;
    p->next = l1 + 5;
    p = p->next;

    p->val = 6;
    p->next = l1 + 6;
    p = p->next;

    p->val = 2;
    p->next = l1 + 7;
    p = p->next;

    p->val = 3;
    p->next = l1 + 8;
    p = p->next;

    p->val = 6;
    p->next = NULL;

    /* 6 -> 6 -> 1 -> 6 -> 6 -> 6 -> 2 -> 3 -> 6 */
    p = l1;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = removeElements(l1, 6);

    /* 1 -> 2 -> 3 */
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
