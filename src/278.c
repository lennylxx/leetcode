#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define BAD 3 // for testing

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    return (version >= BAD);
}

int firstBadVersion(int n) {
    if (n <= 1) return n;

    int low = 1;
    int high = n;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {

    assert(firstBadVersion(3) == 3);
    assert(firstBadVersion(4) == 3);
    assert(firstBadVersion(5) == 3);
    assert(firstBadVersion(6) == 3);
    assert(firstBadVersion(7) == 3);
    assert(firstBadVersion(8) == 3);
    assert(firstBadVersion(9) == 3);

    return 0;
}
