#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL) return NULL;

    struct ListNode *left, *right;
    struct ListNode *lp, *rp;
    struct ListNode *p;

    left = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    right = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    lp = left;
    rp = right;
    p = head;

    while (p) {
        if (p->val < x) {
            lp->next = p;
            lp = lp->next;
        }
        else {
            rp->next = p;
            rp = rp->next;
        }
        p = p->next;
    }

    lp->next = right->next;
    rp->next = NULL;
    head = left->next;

    free(left); free(right);

    return head;
}

int main() {
    struct ListNode *head = (struct ListNode *)calloc(6, sizeof(struct ListNode));
    struct ListNode *p = head;
    p->val = 1;
    p->next = p + 1;
    p = p->next;
    p->val = 4;
    p->next = p + 1;
    p = p->next;
    p->val = 3;
    p->next = p + 1;
    p = p->next;
    p->val = 2;
    p->next = p + 1;
    p = p->next;
    p->val = 5;
    p->next = p + 1;
    p = p->next;
    p->val = 2;
    p->next = NULL;

    int x = 3;
    p = partition(head, x);

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
