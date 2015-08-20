#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isUgly(int num) {
    if (num <= 0) return false;

    while (num > 1) {
        bool flag = false;

        if (num % 2 == 0) {
            flag = true;
            num /= 2;
        }
        if (num % 3 == 0) {
            flag = true;
            num /= 3;
        }
        if (num % 5 == 0) {
            flag = true;
            num /= 5;
        }

        if (!flag) return false;
    }

    return true;
}

int main() {
    assert(isUgly(0) == false);
    assert(isUgly(1) == true);
    assert(isUgly(6) == true);
    assert(isUgly(14) == false);

    printf("all test passed.\n");
    return 0;
}
