#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  Implement Stack using Linked List.
 */

struct StackNode {
    int val;
    struct StackNode *next;
};

struct Stack {
    struct StackNode *top;
};

void push(struct Stack *stack, int new_val) {
    if (stack == NULL) return;

    struct StackNode *new_node
        = (struct StackNode *)malloc(sizeof(struct StackNode));

    new_node->val = new_val;
    new_node->next = stack->top;

    stack->top = new_node;
}

int pop(struct Stack *stack) {
    if (stack == NULL || stack->top == NULL) return 0;

    struct StackNode *t = stack->top;
    int ans = t->val;

    stack->top = stack->top->next;

    free(t);

    return ans;
}

bool isEmpty(struct Stack *stack) {
    if (stack == NULL) return true;

    return (stack->top == NULL) ? true : false;
}

/**
 *  Implement Queue using two stacks.
 */

typedef struct {
    struct Stack in;
    struct Stack out;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    if (queue == NULL) return;

    /* I'm a queue implemented using linked stack, so I don't need maxSize */
    queue->in.top = queue->out.top = NULL;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    if (queue == NULL) return;

    while (!isEmpty(&queue->out)) {
        int top = pop(&queue->out);
        push(&queue->in, top);
    }

    push(&queue->in, element);
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    if (queue == NULL) return;

    if (isEmpty(&queue->out)) {
        while (!isEmpty(&queue->in)) {
            int top = pop(&queue->in);
            push(&queue->out, top);
        }
    }

    pop(&queue->out);
}

/* Get the front element */
int queuePeek(Queue *queue) {
    if (isEmpty(&queue->out)) {
        while (!isEmpty(&queue->in)) {
            int top = pop(&queue->in);
            push(&queue->out, top);
        }
    }

    if (!isEmpty(&queue->out) && queue->out.top) {
        return queue->out.top->val;
    }
    else {
        return 0;
    }
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    if (isEmpty(&queue->in) && isEmpty(&queue->out)) {
        return true;
    }
    else {
        return false;
    }
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    while (!isEmpty(&queue->in)) {
        pop(&queue->in);
    }

    while (!isEmpty(&queue->out)) {
        pop(&queue->out);
    }
}

int main() {
    int maxSize = 5;
    Queue q;

    printf("Create a queue.\n"); queueCreate(&q, maxSize);

    printf("Push 1\n"); queuePush(&q, 1);
    printf("Push 2\n"); queuePush(&q, 2);
    printf("Push 3\n"); queuePush(&q, 3);
    printf("Push 4\n"); queuePush(&q, 4);

    printf("Peek of queue: %d\n", queuePeek(&q));

    printf("Pop\n"); queuePop(&q);
    printf("Peek of queue: %d\n", queuePeek(&q));
    printf("Push 5\n"); queuePush(&q, 5);
    printf("Peek of queue: %d\n", queuePeek(&q));

    printf("Pop\n"); queuePop(&q);
    printf("Peek of queue: %d\n", queuePeek(&q));
    printf("Pop\n"); queuePop(&q);
    printf("Peek of queue: %d\n", queuePeek(&q));
    printf("Pop\n"); queuePop(&q);
    printf("Peek of queue: %d\n", queuePeek(&q));

    printf("Destroy\n"); queueDestroy(&q);

    return 0;
}
