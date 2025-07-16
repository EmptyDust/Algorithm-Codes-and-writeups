#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
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
    for (int i = 1;i < n;++i)std::cin >> a[i];
    std::vector adj(n, std::vector<a2>());
    for (int i = 1;i < n;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    std::vector<i64> dis(n), ans(n);
    i64 min = 2e18;
    auto dfs = [&](auto&& dfs, int u, int p) ->void {
        for (auto [v, w] : adj[u])if (v != p) {
            dis[v] = dis[u] - a[u] + w;
            ans[v] = std::max(ans[u], dis[v]);
            if (a[u] + a[v] > 2 * w) {
                min = std::min(min, std::max(ans[v], dis[v] - a[v] + w));
            }
            dfs(dfs, v, u);
        }
        };
    dfs(dfs, 0, -1);
    for (int i = 1;i < n;++i)std::cout << std::min(ans[i], min) << ' ';
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