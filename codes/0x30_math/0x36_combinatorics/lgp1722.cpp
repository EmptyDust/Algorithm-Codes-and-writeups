#include<stdio.h>
#include<stdlib.h>
long long c[101] = { 1,1 };
int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = 2;i <= n;i++)
        for (int j = 0;j < i;++j)
            c[i] = (c[i] + c[j] * c[i - 1 - j]) % 100;
    printf("%lld", c[n]);
    return 0;
}