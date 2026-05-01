#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<a3> e(n - 1);
    std::vector<i64> min(n), sel(n);
    std::vector<pii> g[n];
    for (auto& [w, u, v] : e) {
        std::cin >> u >> v >> w, u--, v--;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }
    i64 ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        // std::cout << u << ' ';
        std::vector<i64> get;
        for (auto [v, w] : g[u])if (v != p) {
            dfs(v, u);
            if (sel[v] == k)w -= min[v];
            get.push_back(w);
        }
        ranges::sort(get, std::greater<i64>());
        for (auto x : get) {
            if (sel[u] == k || x <= 0)break;
            ans += x;
            min[u] = x;
            sel[u]++;
        }
        // std::cout << u << ' ' << ans << '\n';
        };
    dfs(0, -1);
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