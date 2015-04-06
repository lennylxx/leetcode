#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
    struct ListNode *front, *rear; /* front and rear node of reversed list */
    struct ListNode *left, *right; /* left and right linked point */
    struct ListNode *p, *q, *t;
    front = rear = left = right = NULL;

    int len = n - m + 1;
    t = head;
    m -= 1;
    while (m--) {
        left = t;
        t = t->next;
    }

    rear = t;
    p = q = NULL;
    while (len--) {
        q = t->next;
        t->next = p;
        p = t;
        t = q;
    }
    right = t;
    front = p;

    /* left to front, rear to right */
    if (left) {
        left->next = front;
    }
    else {
        head = front;
    }
    rear->next = right;

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

    p = l1;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = reverseBetween(l1, 2, 4);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    struct ListNode *l2 = (struct ListNode *)calloc(2, sizeof(struct ListNode));
    l2->val = 3;
    l2->next = l2 + 1;
    l2->next->val = 5;
    l2->next->next = NULL;

    p = l2;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = reverseBetween(l2, 1, 2);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
