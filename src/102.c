#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode {
    void * ptr;
    struct QueueNode *next;
};

struct Queue{
    struct QueueNode *front;
    struct QueueNode *tail;
};

void push(struct Queue *queue, void *new_val) {

    struct QueueNode *new_node = (struct QueueNode *)malloc(sizeof(struct QueueNode));

    new_node->ptr = new_val;
    new_node->next = NULL;

    if (queue->tail != NULL) {
        queue->tail->next = new_node;
    }

    queue->tail = new_node;

    if (queue->front == NULL) {
        queue->front = new_node;
    }
}

void * pop(struct Queue * queue) {
    void *ans;
    if (queue->front == NULL) {
        ans = NULL;
    }
    else {
        ans = queue->front->ptr;
        struct QueueNode *tmp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->tail = NULL;
        }
        free(tmp);
    }

    return ans;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) return NULL;

#define MAX 4096
    int **ans = (int **)calloc(MAX, sizeof(int *));
    *columnSizes = (int *)calloc(MAX, sizeof(int));

    struct Queue q;
    q.front = q.tail = NULL;
    push(&q, root);

    ans[0] = (int *)calloc(1, sizeof(int)); /* for the root node */

    *returnSize = 0;
    int next = 0; /* number of nodes in next level, except NULL nodes */
    int cur = 1; /* number of nodes in current level, except NULL nodes */
    int count = 0; /* count of nodes already traversed in current level */

    while (q.front != NULL) {
        struct TreeNode *p = (struct TreeNode *)pop(&q);

        if (p) { /* push children into queue if parent is not NULL */
            ans[*returnSize][count] = p->val;
            count++;

            if (p->left) {
                push(&q, p->left);
                next++;
            }
            if (p->right) {
                push(&q, p->right);
                next++;
            }
        }

        if (count == cur) {
            (*columnSizes)[*returnSize] = cur;
            (*returnSize)++;

            ans[*returnSize] = (int *)calloc(next, sizeof(int)); /* for next level */

            cur = next;
            count = next = 0;
        }
    }
    return ans;
}

int main() {

    struct TreeNode *r = (struct TreeNode *)calloc(7, sizeof(struct TreeNode));
    struct TreeNode *p = r;

    p->val = 3;
    p->left = r + 1;
    p->right = r + 2;

    p = r + 1;
    p->val = 9;

    p = r + 2;
    p->val = 20;

    p->left = r + 3;
    p->right = r + 4;

    p = r + 3;
    p->val = 15;

    p = r + 4;
    p->val = 7;

    int *columnSizes = NULL;
    int returnSize = 0;

    int **ret = levelOrder(r, &columnSizes, &returnSize);

    int i, j;
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
        free(ret[i]);
    }
    free(ret);

    free(columnSizes);

    return 0;
}
