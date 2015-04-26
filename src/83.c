#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;

    struct ListNode *pre = head;
    struct ListNode *p = head->next;
    
    while (p) {
        if (pre->val == p->val) {
            p = p->next;
            pre->next = p;
        }
        else {
            pre = p;
            p = p->next;
        }
    }

    return head;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *p = NULL;

    p = l1;
    p->val = 1;
    p->next = l1 + 1;
    p = p->next;

    p->val = 1;
    p->next = l1 + 2;
    p = p->next;

    p->val = 3;
    p->next = l1 + 3;
    p = p->next;

    p->val = 3;
    p->next = l1 + 4;
    p = p->next;

    p->val = 3;
    p->next = NULL;

    p = l1;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = deleteDuplicates(l1);

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
