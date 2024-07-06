#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 5;
using pii = std::pair<int, int>;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)


void solve() {
    int n;std::cin >> n;
    i64 cur = 0;
    for (int i = 0;i < n;++i) {
        int a;char b;
        std::cin >> a >> b;
        int x = b == 'A' ? 10 : b - '0';
        //a1*(1-q)^n/1-q
        cur = (cur * qpow(11, b) % mod + x * (a % 5)) % mod;
    }
    std::cout << (cur ? "No" : "Yes");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}