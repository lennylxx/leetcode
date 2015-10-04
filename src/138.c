#include <stdio.h>
#include <stdlib.h>

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

/*
 * http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
 */

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    if (head == NULL) return NULL;

    struct RandomListNode *new_node = NULL;
    struct RandomListNode *p = head;

    /* original next points to new_node, new_node->next points to original next */
    while (p) {
        new_node = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        new_node->label = p->label;
        new_node->next = p->next;
        p->next = new_node;
        p = new_node->next;
    }

    /* link random pointers */
    p = head;
    struct RandomListNode *new_head = head->next;
    struct RandomListNode *q = NULL;
    while (p) {
        q = p->next;
        if (p->random) {
            q->random = p->random->next;
        }
        else {
            q->random = NULL;
        }
        p = q->next;
    }

    /* restore original link list */
    p = head;
    while (p) {
        q = p->next;
        p->next = q->next;
        p = p->next;
        if (p) {
            q->next = p->next;
        }
        else {
            q->next = NULL;
        }
    }

    return new_head;
}

int main() {

    struct RandomListNode *head
        = (struct RandomListNode *)malloc(4 * sizeof(struct RandomListNode));
    struct RandomListNode *one = head;
    one->label = 1;
    struct RandomListNode *two = head + 1;
    two->label = 2;
    struct RandomListNode *three = head + 2;
    three->label = 3;
    struct RandomListNode *four = head + 3;
    four->label = 4;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    one->random = three;
    two->random = one;
    three->random = NULL;
    four->random = four;

    struct RandomListNode *p = head;
    printf("N  R\n");
    while (p) {
        printf("%d  ", p->label);
        if (p->random) {
            printf("%d\n", p->random->label);
        }
        else {
            printf("NIL\n");
        }
        p = p->next;
    }

    struct RandomListNode *new_head = copyRandomList(head);

    p = new_head;
    printf("Copied:\n");
    printf("N  R\n");
    while (p) {
        printf("%d  ", p->label);
        if (p->random) {
            printf("%d\n", p->random->label);
        }
        else {
            printf("NIL\n");
        }
        p = p->next;
    }

    return 0;
}
