#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct HashNode {
    int data;
    struct HashNode *next;
};

static inline int hash(int num, int size) {
    int index = num % size;
    return (index > 0) ? (index) : (-index);
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize < 2) return false;
    bool duplicated = false;

    int hash_size = numsSize / 2 + 1; /* proper size can be faster */
    struct HashNode **hash_table
        = (struct HashNode **)calloc(hash_size, sizeof(struct HashNode *));

    int i;
    for (i = 0; i < numsSize; i++) {
        int index = hash(nums[i], hash_size);
        struct HashNode **p = hash_table + index;

        while (*p) {
            if ((*p)->data == nums[i]) {
                duplicated = true;
                goto OUT;
            }
            p = &((*p)->next);
        }

        struct HashNode *new_node
            = (struct HashNode *)malloc(sizeof(struct HashNode));
        new_node->data = nums[i];
        new_node->next = NULL;

        *p = new_node;
    }

OUT:
    for (i = 0; i < hash_size; i++) {
        struct HashNode *t = hash_table[i];
        struct HashNode *x = NULL;
        while (t) {
            x = t->next;
            free(t);
            t = x;
        }
    }
    free(hash_table);

    return duplicated;
}

int main() {
    int nums[] = { 1, 3, 5, 7, 9, 7 };
    /* should be 1 */
    printf("%d\n", containsDuplicate(nums, sizeof(nums) / sizeof(nums[0])));

    return 0;
}
