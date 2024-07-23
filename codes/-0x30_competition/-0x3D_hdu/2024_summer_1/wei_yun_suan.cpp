#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x;
        p >>= 1;
        x = x * x;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

i64 comb[16][16];
void init() {
    for (int i = 0;i < 16;++i) {
        comb[i][0] = 1;
        for (int j = 1;j <= i;++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

void solve() {
    int n, k;std::cin >> n >> k;
    int popcount = std::__popcount(n);
    i64 ans = 0;
    for (int ab = 0;ab < (1 << k);++ab) {
        int cnt = 0;
        for (int s = 0;s < k;++s)if (ab >> s & 1) {
            cnt++;
        }
        i64 pow = qpow(3, k - cnt);
        for (int i = 0;i <= popcount;++i) {
            ans += pow * (1 << i) * comb[popcount][i];
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}