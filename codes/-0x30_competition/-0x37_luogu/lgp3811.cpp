#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
void exGCD(int a, int b, int& x, int& y) {
    if (!b) x = 1, y = 0;
    else exGCD(b, a % b, y, x), y -= a / b * x;
}

int exGCDInv(int a, int b) {
    int x, y;
    exGCD(a, b, x, y);
    x = (x % b + b) % b;
    return x;
}

signed main() {
    ios::sync_with_stdio(false);
    int n, p;cin >> n >> p;
    for (int i = 1;i <= n;++i)
        cout << exGCDInv(i, p) << '\n';
    return 0;
}
*/
constexpr int MAXN = 1e7;
int inv[MAXN];
signed main() {
    ios::sync_with_stdio(false);
    int n, p;cin >> n >> p;
    inv[1] = 1;
    for (int i = 2;i <= n;++i)
        inv[i] = (p - p / i) * inv[p % i] % p;
    for (int i = 1;i <= n;++i)
        cout << inv[i] << '\n';

    return 0;
}
