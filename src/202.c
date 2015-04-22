#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct HashNode {
    int key;   /* num  */
    struct HashNode *next;
};

static inline int hash(int key, int size) {
    int index = key % size;
    return (index > 0) ? (index) : (-index);
}

bool isHappy(int n) {
    if (n == 1) return true;

    int size = 128;
    struct HashNode **hashtable
        = (struct HashNode **)calloc(size, sizeof(struct HashNode*));

    while (1) {
        /* check if n has been calculated */
        int index = hash(n, size);
        struct HashNode **p = hashtable + index;
        while (*p){
            if ((*p)->key == n) { /* found, endless loop, n is not happy */
                return false;
            }
            p = &((*p)->next);
        }
        /* put n into hash table */
        struct HashNode *new_node
            = (struct HashNode*)malloc(sizeof(struct HashNode));
        new_node->key = n;
        new_node->next = NULL;
        *p = new_node;

        int t = 0;
        while (n) {
            t += (n % 10) * (n % 10);
            n /= 10;
        }

        if (t == 1) return true;
        else n = t;
    }
}

int main() {
    /* 19 is happy */
    printf("%d\n", isHappy(19));
    /* 1 is happy */
    printf("%d\n", isHappy(1));
    /* 0 is NOT happy */
    printf("%d\n", isHappy(0));

    return 0;
}
