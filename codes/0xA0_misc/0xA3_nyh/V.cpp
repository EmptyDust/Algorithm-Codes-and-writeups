#include <stdio.h>
#include <math.h>

int isPrime(int x) {
    int j;
    for (j = 2;j <= sqrt(x);++j) {
        if (x % j == 0)
            return 0;
    }
    return 1;
}

int main() {
    int m, n, i;
    scanf("%d%d", &m, &n);
    for (i = m;i <= n;++i) {
        if (isPrime(i))
            printf("%d ", i);
    }
    return 0;
}