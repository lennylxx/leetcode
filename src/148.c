#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode *left, struct ListNode *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct ListNode *ans = NULL;
    struct ListNode **p = &ans;

    while (left && right) {
        if (left->val <= right->val) {
            *p = left;
            p = &((*p)->next);
            left = left->next;
        }
        else {
            *p = right;
            p = &((*p)->next);
            right = right->next;
        }
    }

    if (left) {
        *p = left;
    }
    else if (right) {
        *p = right;
    }

    return ans;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    struct ListNode *p = head;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }

    struct ListNode *mid = head;
    struct ListNode *prev = NULL;
    int i = len / 2;
    while (i--) {
        prev = mid;
        mid = mid->next;
    }
    prev->next = NULL;

    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);

    return merge(left, right);
}

int main() {
    struct ListNode *head = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode **p = &head;
    int i;
    for (i = 0; i < 5; i++) {
        (*p)->val = 5 - i;
        (*p)->next = *p + 1;
        p = &((*p)->next);
    }
    *p = NULL;

    printf("List: ");
    struct ListNode *q = head;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    struct ListNode *ret = sortList(head);

    printf("Sort result: ");
    q = ret;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    return 0;
}
