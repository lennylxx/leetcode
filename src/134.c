#include <stdio.h>
#include <assert.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    if (gasSize != costSize) return -1;
    int i;
    int tank = 0, sum = 0;
    int ans = 0;
    for (i = 0; i < gasSize; i++) {
        sum += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if (sum < 0) {
            ans = i + 1;
            sum = 0;
        }
    }

    return tank >= 0 ? ans : -1;
}

int main() {
    int gas[] = { 1, 2 };
    int cost[] = { 2, 1 };

    assert(canCompleteCircuit(gas, sizeof(gas) / sizeof(gas[0]),
                              cost, sizeof(cost) / sizeof(cost[0])) == 1);

    printf("all tests passed!\n");

    return 0;
}
