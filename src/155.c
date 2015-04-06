#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int val;
    struct StackNode *next;
} StackNode;

typedef struct MinStack {
    int size;
    StackNode *top;
    StackNode *min;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    /* I implement a linked stack, so I don't need maxSize */
    if (stack) {
        stack->min = NULL;
        stack->top = NULL;
        stack->size = 0;
    }
}

void minStackPush(MinStack *stack, int element) {
    if (stack) {
        StackNode *new_node = (StackNode *)calloc(1, sizeof(StackNode));
        new_node->val = element;
        new_node->next = stack->top;
        stack->top = new_node;
        stack->size++;
        /* update min pointer */
        StackNode *new_min = (StackNode *)calloc(1, sizeof(StackNode));
        new_min->val = element;
        new_min->next = stack->min;

        if (stack->min) {
            if (stack->min->val >= element){
                stack->min = new_min;
            }
        }
        else {
            stack->min = new_min;
        }
    }
}

void minStackPop(MinStack *stack) {
    if (stack && stack->top) {
        StackNode *t = stack->top;
        stack->top = stack->top->next;
        if (stack->min && t <= stack->min) {
            StackNode *m = stack->min;
            stack->min = stack->min->next;
            free(m);
        }
        stack->size--;
        free(t);
    }
}

int minStackTop(MinStack *stack) {
    if (stack && stack->top) {
        return stack->top->val;
    }
    return 0;
}

int minStackGetMin(MinStack *stack) {
    if (stack && stack->min) {
        return stack->min->val;
    }
    return 0;
}

void minStackDestroy(MinStack *stack) {
    if (stack) {
        while (stack->size != 0) {
            minStackPop(stack);
        }
        while (stack->min != NULL) {
            StackNode *m = stack->min;
            stack->min = stack->min->next;
            free(m);
        }
        /**
         *free(stack);
         *stack = NULL;
         */
    }
}

int main() {
    MinStack stack;
    minStackCreate(&stack, 10);
    int i;
    for (i = 0; i < 5; i++) {
        minStackPush(&stack, i);
    }

    printf("top: %d\n", minStackTop(&stack));
    printf("min: %d\n", minStackGetMin(&stack));

    for (i = 1; i < 5; i++) {
        minStackPush(&stack, -i);
    }

    printf("top: %d\n", minStackTop(&stack));
    printf("min: %d\n", minStackGetMin(&stack));

    minStackDestroy(&stack);

    return 0;
}
