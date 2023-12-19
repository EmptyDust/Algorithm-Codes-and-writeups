#include <bits/stdc++.h>
using namespace std;

void hanno(int a, int b, int c, int n) {
    if (n == 1) {
        printf("move %d to %d\n", a, c);
        return;
    }
    hanno(a, c, b, n - 1);
    printf("move %d to %d\n", a, c);
    hanno(b, a, c, n - 1);
}

int main() {
    int n;cin >> n;
    hanno(0, 1, 2, n);
    return 0;
}