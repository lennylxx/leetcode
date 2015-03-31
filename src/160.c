#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA, lenB;
    lenA = lenB = 0;
    struct ListNode *ptrA, *ptrB;
    ptrA = headA;
    ptrB = headB;

    while (ptrA != 0) {
        lenA++;
        ptrA = ptrA->next;
    }

    while (ptrB != 0) {
        lenB++;
        ptrB = ptrB->next;
    }

    int diff = lenA - lenB;
    ptrA = headA;
    ptrB = headB;

    if (diff > 0) {
        while (diff--)  ptrA = ptrA->next;
    }
    else {
        while (diff++)  ptrB = ptrB->next;
    }

    while (ptrA != 0 && ptrB != 0) {
        if (ptrA == ptrB) {
            return ptrA;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return NULL;
}

int main() {
    struct ListNode *headA
        = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *headB
        = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *headC
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
    for (i = 1; i <= 3; i++) {
        (*p)->val = i + 5;
        (*p)->next = *p + 1;
        p = &(*p)->next;
    }
    *p = headA + 2; /* intersect A and B */

    p = &headC;
    for (i = 1; i <= 3; i++) {
        (*p)->val = i + 5;
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

    printf("List C: ");
    q = headC;
    while (q) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    struct ListNode *ret;

    ret = getIntersectionNode(headA, headB);
    printf("Ptr of A B: %p, val: %d\n", ret, (ret != NULL) ? ret->val : -1);

    ret = getIntersectionNode(headC, headB);
    printf("Ptr of C B: %p, val: %d\n", ret, (ret != NULL) ? ret->val : -1);

    return 0;
}
