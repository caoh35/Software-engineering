/*��ĿҪ��

��Ŀ(1)���������������ͣ�����Ӷκͣ�

����

���⣺ ����n������������Ϊ��������ɵ�����a[1], a[2], a[3], ��, a[n], 
���������a[i] + a[i + 1] + �� + a[j]���Ӷκ͵����ֵ��

��������������Ϊ����ʱ�����Ӷκ�Ϊ0�����˶��壬���������ֵΪ�� 
Max{ 0,a[i] + a[i + 1] + �� + a[j] }, 1 <= i <= j <= n

���磬����a[1], a[2], a[3], a[4], a[5], a[6]�� = (-2, 11, -4, 13, -5, -2)ʱ������Ӷκ�Ϊ20��*/

#include <stdio.h>

// ����������������������
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
    printf("���������еĳ��ȣ�");
    scanf_s("%d", &n);

    int arr[100];
    printf("���������е�Ԫ�أ�");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    int maxSum = maxArr(arr, n);
    printf("��������������Ϊ��%d\n", maxSum);

    return 0;
}