/*题目要求：

题目(1)：最大连续子数组和（最大子段和）

背景

问题： 给定n个整数（可能为负数）组成的序列a[1], a[2], a[3], …, a[n], 
求该序列如a[i] + a[i + 1] + … + a[j]的子段和的最大值。

当所给的整数均为负数时定义子段和为0，依此定义，所求的最优值为： 
Max{ 0,a[i] + a[i + 1] + … + a[j] }, 1 <= i <= j <= n

例如，当（a[1], a[2], a[3], a[4], a[5], a[6]） = (-2, 11, -4, 13, -5, -2)时，最大子段和为20。*/

#include <stdio.h>

// 函数：求最大连续子数组和
int maxArr(int arr[], int n) {
    int maxE = 0;
    int maxS = 0;

    for (int i = 0; i < n; i++) {
        maxE = maxE + arr[i];
        if (maxE < 0) {
            maxE = 0;
        }
        if (maxS < maxE) {
            maxS = maxE;
        }
    }
    return maxS;
}

int main() {
    int n;
    printf("请输入序列的长度：");
    scanf_s("%d", &n);

    int arr[100];
    printf("请输入序列的元素：");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    int maxSum = maxArr(arr, n);
    printf("最大连续子数组和为：%d\n", maxSum);

    return 0;
}