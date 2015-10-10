#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *Helper(struct ListNode **forward, struct ListNode *node) {
    if (node == NULL || node->next == NULL) return node;

    struct ListNode *tail = Helper(forward, node->next);

    if (*forward == tail || (*forward)->next == tail) return tail;

    struct ListNode *t = (*forward)->next;
    (*forward)->next = tail;
    *forward = t;
    tail->next = t;

    return node;
}

void reorderList(struct ListNode* head) {
    if (head == NULL) return;
    struct ListNode *p = head;
    struct ListNode *mid = Helper(&p, head);
    mid->next = NULL;
}

struct ListNode *createNode(int new_data) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = new_data;
    new_node->next = NULL;
    return new_node;
}

int main(){
    /* test 1 */
    struct ListNode *l1 = createNode(1);
    struct ListNode *p = l1;
    int i;
    for (i = 2; i <= 5; i++) {
        p->next = createNode(i);
        p = p->next;
    }
    p->next = NULL;

    printf("List  1: ");
    p = l1;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    reorderList(l1);

    printf("Reorder: ");
    p = l1;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    /* test 2 */
    struct ListNode *l2 = createNode(1);
    p = l2;
    for (i = 2; i <= 6; i++) {
        p->next = createNode(i);
        p = p->next;
    }
    p->next = NULL;

    printf("List  2: ");
    p = l2;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    reorderList(l2);

    printf("Reorder: ");
    p = l2;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NIL\n");

    return 0;
}
