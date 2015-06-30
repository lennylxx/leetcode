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

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;

    struct Queue q;
    q.front = q.tail = NULL;

    push(&q, root);

    while (q.front != NULL) { /* queue is not empty */
        struct TreeNode * p = (struct TreeNode *)pop(&q);

        if (p) {
            struct TreeNode * t = p->left;
            p->left = p->right;
            p->right = t;

            push(&q, p->left);
            push(&q, p->right);
        }
    }

    return root;
}

/* recursive method */
struct TreeNode* invertTree_r(struct TreeNode* root) {
    if (root == NULL) return NULL;

    struct TreeNode *t = root->left;
    root->left = root->right;;
    root->right = t;

    invertTree_r(root->left);
    invertTree_r(root->right);
    return root;
}

int main() {

    struct TreeNode *root = (struct TreeNode *)calloc(5, sizeof(struct TreeNode));
    struct TreeNode *p = root;

    p->left = root + 1;
    p->right = root + 2;

    p = root + 2;
    p->left = root + 3;

    p = root + 3;
    p->left = root + 4;

    root->val = 1;
    (root + 1)->val = 4;
    (root + 2)->val = 3;
    (root + 3)->val = 2;
    (root + 4)->val = 5;

    /* 143##2#5# */
    printTreeLevelOrder(root);

    invertTree(root);

    /* 134#2###5 */
    printTreeLevelOrder(root);

    return 0;
}
