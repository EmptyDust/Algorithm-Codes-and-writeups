#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct Info
{
    i64 len = 0, l = 0, r = 0, ans = 0;
    Info operator+(const Info& info) {
        if (len == 0)return info;
        if (info.len == 0)return *this;
        Info res;
        res.len = len + info.len;
        res.l = len == l ? len + info.l : l;
        res.r = info.len == info.r ? info.len + r : info.r;
        res.ans = (ans + info.ans + (r % mod) * (info.l % mod) % mod) % mod;
        return res;
    }
}dp[61][61];

Info get(int n, int k) {
    if (k >= 0) {
        return dp[n][k];
    }
    return { 1ll << n ,0,0,0 };
}

void solve() {
    i64 n, k;std::cin >> n >> k;

    Info s;
    int c = 0;
    for (int i = 59;i >= 0;--i) {
        if (n >> i & 1) {
            s = s + get(i, k - c);
            c++;
        }
    }
    std::cout << s.ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    for (int i = 0;i <= 60;++i) {
        dp[0][i] = { 1,1,1,1 };
    }

    for (int i = 1;i <= 60;++i) {
        for (int j = 0;j <= 60; ++j) {
            dp[i][j] = get(i - 1, j) + get(i - 1, j - 1);
        }
    }

    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}