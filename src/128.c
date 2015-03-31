#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashNode {
    int key;          /* num[i] */
    int value;        /* i      */
    struct HashNode *next;
};

static inline int hash(int key, int n) {
    int index = key % n;
    return (index > 0) ? (index) : (-index);
}

int calculate(struct HashNode **hashtable, int *length, int x, int n) {
    int index = hash(x, n);
    struct HashNode *p = hashtable[index];
    while (p) {
        if (p->key == x) { /* if found */
            if (length[p->value] == 1) { /* x' length hasn't been calculated */
                length[p->value] = calculate(hashtable, length, x + 1, n) + 1;
            }
            return length[p->value];
        }
        p = p->next;
    }
    return 0;/* not found */
}

int longestConsecutive(int num[], int n) {
    int i;
    struct HashNode **hashtable
        = (struct HashNode **)calloc(n, sizeof(struct HashNode *));

    for (i = 0; i < n; i++) {
        struct HashNode *new_node
            = (struct HashNode *)calloc(1, sizeof(struct HashNode));
        new_node->key = num[i];
        new_node->value = i;
        new_node->next = NULL;
        /* put new node into hash table */
        int index = hash(num[i], n);
        struct HashNode **p = hashtable + index;
        /* get tail */
        while (*p) {
            p = &(*p)->next;
        }
        *p = new_node;
    }

    int *length = (int *)malloc(n * sizeof(int));
    /* set all elements' length to 1 */
    for (i = 0; i < n; i++){
        length[i] = 1;
    }

    /* try to calculate the length of num[i] recursively */
    for (i = 0; i < n; i++) {
        if (length[i] > 1) continue; /* already calculated */
        length[i] = calculate(hashtable, length, num[i] + 1, n) + 1;
    }

    int max_length = 1;
    for (i = 0; i < n; i++){
        if (length[i] > max_length)
            max_length = length[i];
    }
    return max_length;
}

int main() {
    int num1[] = { 100, 4, 200, 1, 3, 2 };
    int num2[] = { 2, 3, 4, 5, 6, 7, 1 };
    /* should be 4 */
    printf("%d\n", longestConsecutive(num1, sizeof(num1) / sizeof(num1[0])));
    /* should be 7 */
    printf("%d\n", longestConsecutive(num2, sizeof(num2) / sizeof(num2[0])));
    return 0;
}
