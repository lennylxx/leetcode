#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* recursive method */
struct ListNode* reverseList_1(struct ListNode *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    struct ListNode *new_head, *new_tail;

    new_head = reverseList_1(head->next);
    new_tail = head->next; /* new_tail may be NULL here, so we add the second */
                           /* if statement. */
    new_tail->next = head;                  
    head->next = NULL;

    return new_head;
}

/* iterative method */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode *prev, *next, *curr;
    prev = next = NULL;
    curr = head;
    while (curr->next) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    curr->next = prev;
    return curr;
}

int main() {
   
    struct ListNode *l1 = (struct ListNode *)calloc(5, sizeof(struct ListNode));

    struct ListNode *p = l1;
    p->val = 1;
    p->next = l1 + 1;
    p = p->next;
    p->val = 2;
    p->next = l1 + 2;
    p = p->next;
    p->val = 3;
    p->next = l1 + 3;
    p = p->next;
    p->val = 4;
    p->next = l1 + 4;
    p = p->next;
    p->val = 5;
    p->next = NULL;

    p = l1;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = reverseList(l1);

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
