#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
bool isPalindrome(struct ListNode* head) {
    if (head == NULL) return true;

    struct ListNode *p = head;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }

    int half = len / 2;

    /* get the middle node */
    p = head;
    while (half--) {
        p = p->next;
    }

    /* skip middle if length is odd */
    if (len % 2 == 1) {
        p = p->next;
    }
    
    /* reverse the right half */
    struct ListNode *prev = NULL, *next = NULL;
    while (p) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    
    struct ListNode *q = prev;
    p = head;
    half = len / 2;

    while (half--) {
        if (p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }

    return true;
}

void printList(struct ListNode* head) {
    if (head == NULL) return;

    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("N\n");
}

int main() {

    struct ListNode *l1 = (struct ListNode *)calloc(4, sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)calloc(5, sizeof(struct ListNode));

    struct ListNode *p = l1;

    p->val = 1;
    p->next = l1 + 1;
    p = p->next;

    p->val = 2;
    p->next = l1 + 2;
    p = p->next;

    p->val = 2;
    p->next = l1 + 3;
    p = p->next;

    p->val = 1;
    p->next = NULL;

    p = l2;
    p->val = 1;
    p->next = l2 + 1;
    p = p->next;

    p->val = 2;
    p->next = l2 + 2;
    p = p->next;

    p->val = 3;
    p->next = l2 + 3;
    p = p->next;

    p->val = 2;
    p->next = l2 + 4;
    p = p->next;

    p->val = 1;
    p->next = NULL;

    printList(l1);
    printf("%d\n", isPalindrome(l1));

    printList(l2);
    printf("%d\n", isPalindrome(l2));

    return 0;
}
