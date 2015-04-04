#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode{
    struct TreeNode *pt;
    int level;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *head;
    struct QueueNode *tail;
};

void push(struct Queue *queue, struct QueueNode *new_node) {

    if (queue->tail) {
        queue->tail->next = new_node;
        new_node->next = NULL;
    }

    queue->tail = new_node;

    if (queue->head == NULL) {
        queue->head = new_node;
    }
}

struct QueueNode pop(struct Queue *queue) {

    struct QueueNode *front = NULL;
    if (queue->head) {
        front = queue->head;
        queue->head = front->next;
        if (queue->head == NULL) queue->tail = NULL;
    }

    struct QueueNode ret;
    memcpy(&ret, front, sizeof(struct QueueNode));

    free(front);
    return ret;
}

/* Fill out 'n' to indicate how many elements return. */
int *rightSideView(struct TreeNode *root, int *n) {
    *n = 0;
    if (!root) return NULL;

#define MAX 1024
    int *ans = (int *)calloc(MAX, sizeof(int));

    struct Queue q;
    q.head = q.tail = NULL;

    struct QueueNode *t = (struct QueueNode *)calloc(1, sizeof(struct QueueNode));
    t->pt = root;
    t->level = 0;

    push(&q, t);

    int lv = 0; /* current level */
    while (q.head != NULL) {
        struct QueueNode p = pop(&q);

        if (p.pt) {
            ans[p.level] = p.pt->val;

            lv = p.level + 1;
            t = (struct QueueNode *)calloc(1, sizeof(struct QueueNode));
            t->pt = p.pt->left;
            t->level = lv;
            push(&q, t);

            t = (struct QueueNode *)calloc(1, sizeof(struct QueueNode));
            t->pt = p.pt->right;
            t->level = lv;
            push(&q, t);
        }
    }

    *n = lv;
    return ans;
}

int main() {
    /**
    *        1            <--- 1
    *      /   \
    *     2     3         <--- 3
    *    / \     \
    *   4   5     6       <--- 6
    *  /         /
    * 7         8         <--- 8
    *  \
    *   9                 <--- 9
    */

    struct TreeNode *root = (struct TreeNode *)calloc(9, sizeof(struct TreeNode));
    struct TreeNode *p = NULL;
    root->val = 1;
    root->left = root + 1;
    root->right = root + 2;

    p = root->left;
    p->val = 2;
    p->left = root + 3;
    p->left->val = 4;
    p->right = root + 4;
    p->right->val = 5;
    p = p->left;
    p->left = root + 5;
    p->left->val = 7;
    p = p->left;
    p->right = root + 6;
    p->right->val = 9;

    p = root->right;
    p->val = 3;
    p->right = root + 7;
    p->right->val = 6;
    p = p->right;
    p->left = root + 8;
    p->left->val = 8;

    /* should be 1 3 6 8 9 */
    int n = 0;
    int *ret = rightSideView(root, &n);

    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");

    return 0;
}