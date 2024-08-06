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
    int n;std::cin >> n;
    std::vector<pii> g[n + 1];
    for (int i = 1;i < n;++i) {
        int u, v, k;std::cin >> u >> v >> k;
        g[u].push_back({ v,k });
        g[v].push_back({ u,k });
    }
    std::vector<double> ans(n + 1);
    ans[1] = 1;
    std::function<void(int, int, int, int)> dfs = [&](int u, int p, int a, int b) {
        if (a + b)
            ans[u] = (double)a / (double)(a + b);

        for (auto [v, k] : g[u])if (v != p) {
            dfs(v, u, a + k, b + !k);
        }
        };
    dfs(1, 0, 0, 0);
    std::function<void(int, int, bool)> dfs2 = [&](int u, int p, bool x) {
        if (x) {
            double tmp = 0;
            for (auto [v, k] : g[u])if (v != p) {
                dfs2(v, u, !x);
                tmp = std::max(tmp, ans[v]);
            }
            // std::cout << u << ' ' << tmp << '\n';
            if (!(g[u].size() == 1 && g[u][0].first == p)) {//非叶子节点 Oscar可以在当前位置停止
                ans[u] = std::min(tmp, ans[u]);
            }
        }
        else {
            for (auto [v, k] : g[u])if (v != p) {
                dfs2(v, u, !x);
                ans[u] = std::min(ans[u], ans[v]);
            }
        }
        };
    dfs2(1, 0, 1);
    std::cout << ans[1];
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(12);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}