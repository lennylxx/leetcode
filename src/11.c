#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int maxArea(int* height, int heightSize);

main() {
	int n;
	printf("Input number of height: ");
	scanf("%d", &n);
	int* height = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		printf("Input height %d: ", i);
		scanf("%d", &height[i]);
	}
	int result = maxArea(height, n);
	printf("Result: %d", result);
	printf("\nOver\n");
}

int maxArea(int* height, int heightSize) {
	int max = 0, area;
	int i = 0, j = heightSize - 1;
	while (i < j) {
		if (height[i] < height[j]) area = height[i] * (j - i);
		else area = height[j] * (j - i);
		if (area > max) max = area;
		if (height[i] < height[j]) i++;
		else j--;
	}
	return max;
}