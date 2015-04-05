#include <stdio.h>

int majorityElement(int num[], int n) {
    int major;
    int i;
    major = num[0];
    int count = 1;
    for (i = 1; i < n; i++) {
        if (num[i] == major) count ++;
        else count --;
        
        if (count == 0) {
            major = num[i];
            count = 1;
        }
    }
    
    return major;
}

int main() {
    
    int num1[] = { 1, 2, 2, 3, 3, 3, 3, 4};
    int num2[] = { 4, 5, 4};
    
    printf("%d\n", majorityElement(num1, sizeof(num1)/sizeof(num1[0])));
    
    printf("%d\n", majorityElement(num2, sizeof(num2)/sizeof(num2[0])));
    
    return 0;
}
