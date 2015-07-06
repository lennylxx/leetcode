#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k == 0) return head;

    struct ListNode **p = &head;
    struct ListNode *new_head = NULL;

    int len = 0;
    while (*p) {
        p = &((*p)->next);
        len++;
    }

    k = k % len; /* important */
    if (k == 0) return head;

    *p = head; /* tail->next = head, make a circle */

    p = &head;
    while (len > k) {
        p = &((*p)->next);
        len--;
    }
    new_head = *p; /* new_head = new_tail->next */
    *p = NULL;    /* new_tail = NULL */

    return new_head;
}

int main() {

    struct ListNode *l1 = (struct ListNode *)calloc(5, sizeof(struct ListNode));

    struct ListNode **p = &l1;
    int i;
    for (i = 1; i <= 5; i++) {
        (*p)->val = i;
        (*p)->next = *p + 1;
        p = &(*p)->next;
    }
    *p = NULL;

    printf("List: ");
    struct ListNode *q = l1;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    int k = 2;
    printf("Rotate right by %d.\n", k);

    struct ListNode *ret = rotateRight(l1, k);

    printf("Result: ");
    q = ret;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    return 0;
}
