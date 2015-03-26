#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int val;
    struct Node *next;
};

void push(struct Node** top_pt, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = new_data;
    new_node->next = *top_pt;
    
    *top_pt = new_node;
}

int pop(struct Node** top_pt)
{
    if (*top_pt == NULL)
    {
        printf("stack overflow\n");
        exit(0);
    }
    struct Node *top = *top_pt;
    int res = top->val;
    *top_pt = top->next;
    free(top);
    return res;
}

int evalRPN(char *tokens[], int n) {
    struct Node *stack = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(tokens[i], "+") == 0) {
            int r = pop(&stack);
            int l = pop(&stack);
            push(&stack, l + r);
        }
        else if (strcmp(tokens[i], "-") == 0) {
            int r = pop(&stack);
            int l = pop(&stack);
            push(&stack, l - r);
        }
        else if (strcmp(tokens[i], "*") == 0) {
            int r = pop(&stack);
            int l = pop(&stack);
            push(&stack, l * r);
        }
        else if (strcmp(tokens[i], "/") == 0) {
            int r = pop(&stack);
            int l = pop(&stack);
            push(&stack, l / r);
        }
        else
            push(&stack, atoi(tokens[i]));
    }
    return pop(&stack);
}

void print_stack(struct Node** top_pt)
{
    struct Node *t = *top_pt;
    while (t != NULL)
    {
        struct Node *tmp_node = t;
        printf("%d ", tmp_node->val);
        t = tmp_node->next;
    }
    printf("\n");
}

int main()
{
    char *tokens[] = {"3","-4","+"};
    printf("%d\n", evalRPN(tokens, sizeof(tokens)/ sizeof(tokens[0])));
    return 0;
}

