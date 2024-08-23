#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector<pii> adj[n];
    for (int i = 1;i < n;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    std::vector<pii> ans(n);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        auto& [x, y] = ans[u];
        for (auto [v, w] : adj[u])if (v != p) {
            dfs(v, u);
            auto& [cx, cy] = ans[v];
            if (a[v] == 3) {
                if (a[u] == 1 || a[u] == 3)
                    x += std::min(cx, cy + w);
                if (a[u] == 2 || a[u] == 3)
                    y += std::min(cy, cx + w);
            }
            else if (a[v] == 1) {
                if (a[u] == 1 || a[u] == 3) x += cx;
                if (a[u] == 2 || a[u] == 3) y += cx + w;
            }
            else if (a[v] == 2) {
                if (a[u] == 1 || a[u] == 3) x += cy + w;
                if (a[u] == 2 || a[u] == 3) y += cy;
            }
        }
        };
    dfs(0, -1);
    if (a[0] == 3)std::cout << std::min(ans[0].first, ans[0].second);
    else if (a[0] == 1)std::cout << ans[0].first;
    else std::cout << ans[0].second;
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