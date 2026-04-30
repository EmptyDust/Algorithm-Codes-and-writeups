#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 n, m;std::cin >> n >> m;

    std::map<i64, i64> mp;
    for (int i = 0;i < n;++i) {
        i64 x;std::cin >> x;
        mp[x]++;
    }
    i64 ans = 0;
    for (auto [x, a] : mp) {
        if (!mp.count(x + 1)) {
            i64 res = std::min(a, m / x) * x;
            ans = std::max(ans, res);
            continue;
        }
        i64 b = mp[x + 1];
        i64 sum = a * x + b * (x + 1);
        if (sum <= m) {
            ans = std::max(ans, sum);
            continue;
        }
        i64 x_c = m - std::min(a, m / x) * x;
        i64 use = std::min(b, x_c / (x + 1));
        x_c -= use * (x + 1);
        b -= use;
        i64 c = std::min({ a,m / x,b,x_c });
        i64 res = m - (x_c - c);
        ans = std::max(ans, res);
    }
    std::cout << ans;
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