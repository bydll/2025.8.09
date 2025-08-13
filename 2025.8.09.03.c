#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(float*)a > *(float*)b) - (*(float*)a < *(float*)b);
}

int main() {
    int n;
    scanf("%d", &n);         // 先输入个数
    float arr[n];
    for(int i=0; i<n; i++)   // 输入数组
        scanf("%f", &arr[i]);

    qsort(arr, n, sizeof(float), cmp); // 排序

    for(int i=0; i<n; i++)   // 输出结果
        printf("%g ", arr[i]);
}