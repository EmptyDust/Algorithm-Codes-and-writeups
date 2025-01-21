#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

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
    int n;std::cin >> n;
    std::vector adj(n, std::vector<int>());
    std::vector<i64> cnt(n), wei(n, 1), add(n), leaf(n);

    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++;cnt[v]++;
    }

    i64 count = 0;
    for (int i = 0;i < n;++i)if (cnt[i] == 1) {
        count++;
        wei[i] = 0;
        leaf[i] = 1;
        for (auto v : adj[i]) {
            wei[v] = 0;
            add[v] = 1;
            // std::cout << v << " ";
        }
    }
    // for (int x : add)std::cout << x << " ";std::cout << '\n';
    for (int i = 0;i < n;++i) {
        if (leaf[i]) add[i] = 0;
    }
    i64 ans = count * (n - count);

    std::vector<i64> dp1(n), dp2(n);
    auto dfs1 = [&](auto&& self, int u, int p) ->void {
        for (auto v : adj[u])if (v != p) {
            self(self, v, u);
            auto tp_dp2v = (add[u] && adj[v].size() != 1);
            if (add[u]) ans += dp1[v] * dp2[u] + tp_dp2v * dp1[u];
            dp1[u] += dp1[v];
            // if (u == 3 && v == 4)std::cout << tp_dp2v << '\n';
            dp2[u] += tp_dp2v;
        }
        dp1[u] += wei[u];
        };
    dfs1(dfs1, 0, -1);

    // for (int x : dp)std::cout << x << " ";std::cout << '\n';

    auto dfs2 = [&](auto&& self, int u, int p, i64 mul1, i64 mul2) ->void {
        if (p != -1) mul2 = (add[u] && adj[p].size() != 1);
        // std::cout << u << ' ' << dp1[u] << " " << dp2[u] << ' ' << mul1 << ' ' << mul2 << '\n';
        if (add[u] && p != -1) ans += dp2[u] * mul1 + dp1[u] * mul2;
        for (auto v : adj[u])if (v != p) {
            auto tp_dp2v = (add[v] && adj[v].size() != 1);
            self(self, v, u, mul1 + dp1[u] - dp1[v], mul2 + dp2[u] - tp_dp2v);
        }
        };
    dfs2(dfs2, 0, -1, 0, 0);

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