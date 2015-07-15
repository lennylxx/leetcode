#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    if (node == NULL || node->next == NULL) return;

    node->val = node->next->val;
    node->next = node->next->next;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("N\n");
}

int main() {

    struct ListNode *l1 = (struct ListNode *)calloc(3, sizeof(struct ListNode));

    l1->val = 1;
    l1->next = l1 + 1;

    l1->next->val = 2;
    l1->next->next = l1 + 2;

    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    printList(l1);

    /* delete 2 */
    deleteNode(l1->next);

    printList(l1);

    return 0;
}
