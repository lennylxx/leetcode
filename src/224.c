#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackNode {
    int val;
    struct StackNode *next;
};

struct Stack {
    struct StackNode *top;
    struct StackNode *bottom;
};

void push(struct Stack *stack, int new_val) {
    if (stack == NULL) return;

    struct StackNode* new_node
    = (struct StackNode *)malloc(sizeof(struct StackNode));

    new_node->val = new_val;
    new_node->next = stack->top;

    stack->top = new_node;

    if (stack->bottom == NULL) {
        stack->bottom = new_node;
    }
}

void pop(struct Stack *stack) {
    if (stack == NULL || stack->top == NULL) return;

    struct StackNode *t = stack->top;
    stack->top = stack->top->next;

    free(t);

    if (stack->top == NULL) {
        stack->bottom = NULL;
    }
}

int top(struct Stack *stack) {
    int ret = 0;
    if (stack != NULL && stack->top != NULL) {
        ret = stack->top->val;
    }
    return ret;
}

void destory(struct Stack *stack) {
    if (stack == NULL || stack->top == NULL) return;

    struct StackNode *t = NULL;
    while (stack->top) {
        t = stack->top;
        stack->top = stack->top->next;

        free(t);
    }

    stack->bottom = NULL;
}

int calculate(char* s) {
    int ans = 0;
    int n = 0;
    char last_op = '+'; /* last operator */
    bool flag = false;  /* whether change the operator in parens or not */

    struct Stack stack;
    stack.top = stack.bottom = NULL;

    push(&stack, flag);

    while (*s != '\0') {
        while (*s == ' ' || *s == '(') {
            if (*s == '(') {
                flag = (last_op == '-') ? true : false;
                push(&stack, flag);
            }
            s++;
        }

        /* get an number */
        n = 0;
        while (*s >= '0' && *s <= '9') {
            n = n * 10 + *s - '0';
            s++;
        }

        /* do the math */
        if (last_op == '+') {
            ans += n;
        }
        else if (last_op == '-') {
            ans -= n;
        }

        /* get next operator */
        while (*s == ' ' || *s == ')') {
            if (*s == ')') {
                pop(&stack);
                flag = top(&stack);
            }
            s++;
        }

        if (flag) {
            last_op = (*s == '+') ? '-' : '+';
        }
        else {
            last_op = *s;
        }
        s++;
    }

    destory(&stack);
    return ans;
}

int main() {

    char *s1 = "2-4-(8+2-6+(8+4-(1)+8-10))";
    /* should be -15 */
    printf("%s = %d\n", s1, calculate(s1));

    char *s2 = "1-(2-(3-(4-5)))";
    /* should be 3 */
    printf("%s = %d\n", s2, calculate(s2));

    return 0;
}
