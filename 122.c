#include <stdio.h>

int maxProfit(int prices[], int n){
    int i;
    int ret = 0;
    for (i = 1; i < n; i++) {
        int t = prices[i] - prices[i - 1];
        if (t > 0)
            ret += t;
    }
    return ret;
}

int main() {
    int prices[] = {1, 2, 3, 2, 4};
    printf("%d\n", maxProfit(prices, sizeof(prices)/sizeof(prices[0])));
}