#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int q[], int l, int r)
{
    //递归的终止情况
    if (l >= r) return;

    //选取分界线。这里选数组中间那个数
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    //划分成左右两个部分
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(&q[i], &q[j]);
    }
    //对左右部分排序
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main() {
    int n, i;
    int nums[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    quick_sort(nums, 0, n - 1);
    for (int i = 0;i < n;++i)printf("%d ", nums[i]);
    return 0;
}