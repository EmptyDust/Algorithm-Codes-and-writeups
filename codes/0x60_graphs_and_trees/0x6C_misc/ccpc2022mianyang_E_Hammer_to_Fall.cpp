#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using a2 = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 1e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, q;std::cin >> n >> m >> q;
    const int B = std::sqrt(m * std::__lg(n));

    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector g(n, std::vector<a2>());
    std::vector h(n, std::vector<a2>());
    for (int i = 0;i < m;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }

    std::vector st(n, std::multiset<i64>());
    for (int u = 0;u < n;++u)if (g[u].size() > B) {
        for (auto [v, w] : g[u]) {
            st[u].insert(w);
            h[v].push_back({ u,w });
        }
    }

    std::vector<int> b(q);
    for(auto &x:b)std::cin>>x,x--;
    std::vector<i64> dp(n);
    for (int i = q - 1;i >= 0;--i) {
        int u = b[i];
        for (auto [v, w] : h[u]){
            st[v].extract(dp[u] + w);
        }
        dp[u] = inf;
        if (g[u].size() <= B) {
            for (auto [v, w] : g[u]) {
                dp[u] = std::min(dp[u], dp[v] + w);
            }
        }
        else {
            dp[u] = *st[u].begin();
        }
        for (auto [v, w] : h[u]){
            st[v].insert(dp[u] + w);
        }
    }
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        dp[i] %= mod;
        ans += dp[i] * a[i] % mod;
        ans %= mod;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
} 