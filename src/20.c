#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

struct Node {
    char val;
    struct Node *next;
};

void push(struct Node** top_pt, char new_data)
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
    char res = top->val;
    *top_pt = top->next;
    free(top);
    return res;
}

bool isValid(char *s) {
    struct Node *stack = NULL;
    int i;
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(&stack, s[i]);
        }
        else {
            if (stack == NULL)
                return false;
            char top = pop(&stack);
            if (s[i] == ')') {
                if (top != '(') return false;
            }
            else if (s[i] == ']'){
                if (top != '[') return false;
            }
            else if (s[i] == '}'){
                if (top != '{') return false;
            }
        }
    }
    if (stack == NULL)
        return true;
    else
        return false;
}

void print_stack(struct Node** top_pt)
{
    struct Node *t = *top_pt;
    while (t != NULL)
    {
        struct Node *tmp_node = t;
        printf("%c ", tmp_node->val);
        t = tmp_node->next;
    }
    printf("\n");
}

int main()
{
    char s[] = "]";
    printf("%d\n", isValid(s));
    return 0;
}
