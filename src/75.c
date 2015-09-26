#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

/* Dutch national flag problem.
 * three way partition, just like radix sort
 */
void sortColors(int* nums, int numsSize) {
    int i, zero, two;
    i = 0;
    zero = 0;
    two = numsSize - 1;

    while (i <= two) {
        if (nums[i] == 0) {
            swap(&nums[i], &nums[zero++]);
            i++; /* index i scans from left to right, so we don't need to check
                  * if left side have 2, just swap and move forward. 
                  * And, if the numbers are all 0, we must move forward, 
                  * otherwise we will loop forever.
                  */
        }
        else if (nums[i] == 2) {
            swap(&nums[i], &nums[two--]);
            /* right side may have 0, so we stop at this position and check 
             * repeatedly. the loop will exit if pointer two is smaller than i.
             */
        }
        else {
            i++;
        }
    }
}

int main() {
    int nums[] = { 1, 2, 0, 1, 0, 2, 0, 0, 1, 0, 2, 1 };
    int size = sizeof(nums) / sizeof(nums[0]);
    sortColors(nums, size);
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
