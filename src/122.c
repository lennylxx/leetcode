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

/*
int maxProfit(int prices[], int n){
    int i;
    int ret = 0;
    int min = prices[0];
    for (i = 1; i < n; i++) {
        if (prices[i] < prices[i - 1]) {
            ret += prices[i - 1] - min;
            min = prices[i];
        }
    }
    if (prices[n - 1] > min)
        ret += prices[n - 1] - min;
    
    return ret;
}
*/

int main() {
    int prices[] = {1, 2, 3, 2, 4};
    printf("%d\n", maxProfit(prices, sizeof(prices)/sizeof(prices[0])));
    return 0;
}
