#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int data) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k <= 1 || head == NULL) return head;

    struct ListNode *leap = head, *next_leap = NULL;
    struct ListNode *milestone = NULL, *next_milestone = NULL;
    struct ListNode *new_head = NULL;
    bool first = true;
    int len = 0;
    while (leap) {
        leap = leap->next;
        len++;
    }

    if (k > len) return head;

    leap = head;
    while (leap) {
        int step = k - 1;
        milestone = leap;
        while (milestone && step) {
            milestone = milestone->next;
            step--;
        }

        if (milestone == NULL) {
            break;
        }

        step = k - 1;
        next_milestone = milestone->next;
        while (next_milestone && step) {
            next_milestone = next_milestone->next;
            step--;
        }

        if (next_milestone == NULL) {
            next_milestone = (milestone == NULL) ? NULL : milestone->next;
        }

        next_leap = milestone->next;
        milestone->next = NULL;

        /* reverse group */
        struct ListNode *p = leap, *q = NULL, *t = NULL;
        while (p) {
            t = p->next;
            p->next = q;
            q = p;
            p = t;
        }
        leap->next = next_milestone; /* group tail to next milestone */

        if (first) {
            new_head = milestone;
            first = false;
        }

        leap = next_leap;
    }

    return new_head;
}

int main() {
    int n = 5;
    int k = 3;

    struct ListNode *head = createNode(1);
    struct ListNode *p = head;

    int i;
    for (i = 2; i <= n; i++) {
        p->next = createNode(i);
        p = p->next;
    }

    p = head;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    struct ListNode *new_head = reverseKGroup(head, k);

    p = new_head;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    return 0;
}
