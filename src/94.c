#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct StackNode {
    struct TreeNode *val;
    struct StackNode *next;
};

struct Stack {
    struct StackNode *top_pt;
    int size;
};

void push(struct Stack *stack, struct TreeNode *new_data) {
    if (stack) {
        struct StackNode *new_node
            = (struct StackNode *)calloc(1, sizeof(struct StackNode));
        new_node->val = new_data;
        new_node->next = stack->top_pt;

        stack->top_pt = new_node;
        stack->size++;
    }
}

struct TreeNode* top(struct Stack stack) {
    if (stack.top_pt) {
        return stack.top_pt->val;
    }
    else return NULL;
}

void pop(struct Stack *stack) {
    if (stack && stack->top_pt) {
        struct StackNode *top = stack->top_pt;
        stack->top_pt = top->next;
        stack->size--;
        free(top);
    }
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    struct Stack stack;
    stack.top_pt = NULL;
    stack.size = 0;

    int *ret = (int *)calloc(1024, sizeof(int));
    struct TreeNode *p = root;
    while (stack.size || p) {
        if (p) {
            push(&stack, p);
            p = p->left;
        }
        else {
            p = top(stack);
            pop(&stack);
            ret[(*returnSize)++] = p->val;
            p = p->right;
        }
    }
    return ret;
}

int main() {
    struct TreeNode *t = (struct TreeNode *)calloc(5, sizeof(struct TreeNode));
    struct TreeNode *p = t;
    p->val = 4;

    p->left = ++t;
    t->val = 2;
    p->left->left = ++t;
    t->val = 1;
    t->left = t->right = NULL;
    p->left->right = ++t;
    t->val = 3;
    t->left = t->right = NULL;

    p->right = ++t;
    t->val = 5;
    t->left = t->right = NULL;

    int size = 0;
    int *ret = inorderTraversal(p, &size);
    int i;
    /* should be 12345 */
    for (i = 0; i < size; i++) {
        printf("%d", ret[i]);
    }
    printf("\n");

    return 0;
}
