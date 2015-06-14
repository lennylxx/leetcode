#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
    Implement Queue using Linked List.
 */

struct QueueNode {
    int val;
    struct QueueNode *next;
};

struct Queue{
    int size;
    struct QueueNode *front;
    struct QueueNode *tail;
};

void push(struct Queue *queue, int new_val) {
    if (queue == NULL) return;

    struct QueueNode *new_node = (struct QueueNode *)malloc(sizeof(struct QueueNode));

    new_node->val = new_val;
    new_node->next = NULL;

    if (queue->tail != NULL) {
        queue->tail->next = new_node;
    }

    queue->tail = new_node;

    if (queue->front == NULL) {
        queue->front = new_node;
        queue->size = 1;
    }
    else{
        queue->size++;
    }
}

void pop(struct Queue *queue) {
    if (queue == NULL || queue->front == NULL) return;

    struct QueueNode *tmp = queue->front;
    queue->front = queue->front->next;

    free(tmp);
    queue->size--;

    if (queue->front == NULL) {
        queue->tail = NULL;
        queue->size = 0;
    }
}

int size(struct Queue *queue) {
    if (queue == NULL) {
        return 0;
    }
    else {
        return queue->size;
    }
}

bool isEmpty(struct Queue *queue) {
    if (queue == NULL) {
        return true;
    }
    else {
        return (queue->size == 0) ? true : false;
    }
}

/**
    Implement Stack using Queues.
 */

typedef struct {
    struct Queue queue;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    if (stack == NULL) return;

    /* I'm a stack implemented using linked queue, so I don't need maxSize */
    stack->queue.front = stack->queue.tail = 0;
    stack->queue.size = 0;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    if (stack == NULL) return;

    push(&stack->queue, element);
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    if (stack == NULL) return;

    int originalSize = size(&stack->queue);
    int i;
    for (i = 0; i < originalSize - 1; i++) {
        if (stack->queue.front == NULL) {
            return;
        }
        int tmp = stack->queue.front->val;
        pop(&stack->queue);
        push(&stack->queue, tmp);
    }

    pop(&stack->queue);
}

/* Get the top element */
int stackTop(Stack *stack) {
    if (stack == NULL || stack->queue.tail == NULL) {
        return 0;
    }
    else {
        return stack->queue.tail->val;
    }
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    if (stack == NULL) return true;

    return isEmpty(&stack->queue);
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    if (stack == NULL) return;

    while (size(&stack->queue) > 0) {
        pop(&stack->queue);
    }
}

int main() {

    Stack s;
    int maxSize = 5;
    stackCreate(&s, maxSize);

    printf("push 1 to stack.\n");
    stackPush(&s, 1);

    printf("push 2 to stack.\n");
    stackPush(&s, 2);

    printf("push 3 to stack.\n");
    stackPush(&s, 3);

    printf("current top of stack is: %d.\n", stackTop(&s));
    printf("stack is empty? %d.\n", stackEmpty(&s));

    printf("pop from stack.\n");
    stackPop(&s);

    printf("current top of stack is: %d.\n", stackTop(&s));

    printf("destroy stack.\n");
    stackDestroy(&s);

    printf("current top of stack is: %d.\n", stackTop(&s));
    printf("stack is empty? %d.\n", stackEmpty(&s));

    return 0;
}
