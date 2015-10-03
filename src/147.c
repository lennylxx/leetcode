#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode *t = dummy;

    struct ListNode *p;
    struct ListNode *min_ptr, *min_prev; /* prev node of min node */
    int min_val;
    p = head;

    while (p) {
        min_val = p->val;
        min_ptr = p;
        min_prev = NULL;

        struct ListNode *q = p->next;
        struct ListNode *prev = p;
        while (q) {
            if (q->val < min_val) {
                min_val = q->val;
                min_prev = prev;
                min_ptr = q;
            }
            prev = q;
            q = q->next;
        }

        if (p == min_ptr) { /* if min node is p, we don't need to modify list */
            p = p->next;    /* just move forward p, and the min_prev is still */
        }                   /* NULL now. */
        else {
            min_prev->next = min_ptr->next; /* take node from list */
        }
        t->next = min_ptr;
        t = t->next;
    }
    t->next = NULL;

    t = dummy->next;
    free(dummy);

    return t;
}

void print(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("NIL\n");
}

int main() {
    int n = 10;
    struct ListNode *head = (struct ListNode *)calloc(n, sizeof(struct ListNode));
    struct ListNode **p = &head;
    int i;

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        (*p)->val = rand() % n;
        (*p)->next = *p + 1;
        p = &((*p)->next);
    }
    *p = NULL;

    printf("List:   ");
    print(head);

    struct ListNode *new_head = insertionSortList(head);

    printf("Sorted: ");
    print(new_head);

    return 0;
}
