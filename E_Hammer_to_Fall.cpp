#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, q;std::cin >> n >> m >> q;
    const int B = std::sqrt(m * std::__lg(n));

    std::vector<int> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    std::vector<pii> g[n];
    for (int i = 0;i < m;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }

    std::set<a3> st[n];
    for (int u = 0;u < n;++u)if (g[u].size() > B) {
        for (auto [v, w] : g[u]) {
            st[u].insert({ w,w,u });
        }
    }

    std::vector<int> b(q);
    for (int i = 0;i < q;++i)std::cin >> b[i];
    std::vector<int> dp(n);
    for (int i = q - 1;i >= 0;--i) {
        int u = b[i];
        if (g[u].size() <= B) {

        }
        else {
            while (1) {
                auto [d, w, p] = *st[u].begin();
                if (d != dp[p] + w)continue;

            }
        }
    }
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