#include<stdio.h>
constexpr int MAXN = 1e6;
int nums[MAXN];

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int n, i, j;

    scanf("%d", &n);

    for (i = 0, j = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        swap(&nums[i], &nums[j]);
        if (nums[j] != 0)
            ++j;
    }

    for (i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}