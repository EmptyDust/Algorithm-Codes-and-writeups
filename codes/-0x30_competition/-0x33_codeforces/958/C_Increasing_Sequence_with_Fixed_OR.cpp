#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 n;std::cin >> n;
    std::vector<int> p;
    i64 _n = n;
    for (int s = 60;s >= 0;--s)if (n >> s & 1)p.push_back(s);
    std::vector<i64> ans;
    for (int x : p) {
        auto y = n ^ (1ll << x);
        if (y != 0)
            ans.push_back(y);
    }
    ans.push_back(n);
    std::cout << ans.size() << '\n';
    for (auto x : ans)std::cout << x << " ";
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