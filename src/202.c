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

bool isHappy_1(int n) {
    if (n == 1) return true;

    int i;
    bool isHappy = false;
    int size = 20;
    struct HashNode **hashtable
        = (struct HashNode **)calloc(size, sizeof(struct HashNode*));

    while (1) {
        /* check if n has been calculated */
        int index = hash(n, size);
        struct HashNode **p = hashtable + index;
        while (*p){
            if ((*p)->key == n) { /* found, endless loop, n is not happy */
                isHappy = false;
                goto OUT;
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

        if (t == 1) {
            isHappy = true;
            goto OUT;
        }
        else n = t;
    }

OUT:
    /* free memory */
    for (i = 0; i < size; i++) {
        struct HashNode *t = hashtable[i];
        struct HashNode *x = NULL;
        while (t) {
            x = t->next;
            free(t);
            t = x;
        }
    }
    free(hashtable);

    return isHappy;
}

/**
 * If a number is NOT happy, there is always a 4 in the cycle.
 * https://en.wikipedia.org/wiki/Happy_number#Sequence_behavior
 */
bool isHappy(int n) {
    if (n <= 0) return false;
    
    int magic = 4;
    while (1) {
        if (n == 1) return true;
        if (n == magic) return false;
        int t = 0;
        while (n) {
            t += (n % 10) * (n % 10);
            n /= 10;
        }
        n = t;
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
