#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *p = head;
    struct ListNode *q = head->next;
    struct ListNode *new_head = q;
    struct ListNode *t = NULL;

    while (p && q) {
        t = q->next;
        q->next = p;
        if (t && t->next) {
            p->next = t->next;
        }
        else {
            p->next = t;
            break;
        }
        p = t;
        q = p->next;
    }

    return new_head;
}

int main() {
    int n = 5;
    struct ListNode *head = (struct ListNode *)calloc(n, sizeof(struct ListNode));
    struct ListNode *p = head;
    int i;
    for (i = 0; i < n - 1; i++) {
        p->val = i + 1;
        p->next = p + 1;
        p = p->next;
    }
    p->val = n;
    p->next = NULL;

    printf("Linked List: ");
    p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = swapPairs(head);

    printf("Swap Pairs: ");
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
