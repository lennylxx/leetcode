#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    struct ListNode *ret = NULL;
    struct ListNode **p = &ret;

    while (1) {
        if (p1 && p2) {
            if (p1->val <= p2->val) {
                *p = p1;
                p1 = p1->next;
            }
            else {
                *p = p2;
                p2 = p2->next;
            }
        }
        else if (p1 && p2 == NULL) {
            *p = p1;
            p1 = p1->next;
        }
        else if (p2 && p1 == NULL) {
            *p = p2;
            p2 = p2->next;
        }
        else break;

        p = &((*p)->next);
    }

    return ret;
}

int main() {

    struct ListNode *headA
        = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *headB
        = (struct ListNode *)calloc(3, sizeof(struct ListNode));

    struct ListNode **p = &headA;
    int i;
    for (i = 1; i <= 5; i++) {
        (*p)->val = i;
        (*p)->next = *p + 1;
        p = &(*p)->next;
    }
    *p = NULL;

    p = &headB;
    for (i = 3; i <= 7; i += 2) {
        (*p)->val = i;
        (*p)->next = *p + 1;
        p = &(*p)->next;
    }
    *p = NULL;

    printf("List A: ");
    struct ListNode *q = headA;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    printf("List B: ");
    q = headB;
    while (q) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    struct ListNode *ret = mergeTwoLists(headA, headB);

    printf("Merged: ");
    q = ret;
    while (q) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    return 0;
}
