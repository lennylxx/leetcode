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

void printTreeLevelOrder(struct TreeNode *root) {
    struct Queue q;
    q.front = q.tail = NULL;
    push(&q, root);

    while (q.front != NULL) {
        struct TreeNode * p = (struct TreeNode *)pop(&q);

        if (p) {
            printf("%d", p->val);

            push(&q, p->left);
            push(&q, p->right);
        }
        else {
            printf("#");
        }
    }

    printf("\n");
}

/* recursive */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return NULL;

    int middle = numsSize / 2; /* when numsSize is even, it's the right one */

    struct TreeNode *root
        = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[middle];

    root->left = sortedArrayToBST(nums, middle);
    root->right = sortedArrayToBST(nums + middle + 1, numsSize - middle - 1);

    return root;
}

int main () {
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    struct TreeNode *r = sortedArrayToBST(nums, sizeof(nums) / sizeof(nums[0]));

    /* 53824791###6### */
    printTreeLevelOrder(r);

    return 0;
}
