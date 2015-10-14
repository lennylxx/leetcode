#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode *pre = dummy;
    struct ListNode *p = dummy->next;
    struct ListNode *q = dummy->next->next;

    while (p && q) {
        if (p->val == q->val) {
            pre->next = q->next;
        }
        else if (pre->next != q) {
            pre = pre->next;
        }
        p = p->next;
        q = q->next;
    }

    struct ListNode *new_head = dummy->next;
    free(dummy);

    return new_head;
}

struct ListNode * buildList(int *nums, int numsSize) {
    if (numsSize == 0) return NULL;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    struct ListNode *p = dummy;
    for (int i = 0; i < numsSize; i++) {
        p->next = malloc(sizeof(struct ListNode));
        p->next->val = nums[i];
        p = p->next;
    }
    p->next = NULL;

    p = dummy->next;
    free(dummy);

    return p;
}

int main() {

    int nums[] = { 1, 2, 2, 2, 3, 3 };
    struct ListNode *head = buildList(nums, sizeof(nums) / sizeof(nums[0]));
    struct ListNode *p = head;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    struct ListNode *new_head = deleteDuplicates(head);

    p = new_head;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    return 0;
}
