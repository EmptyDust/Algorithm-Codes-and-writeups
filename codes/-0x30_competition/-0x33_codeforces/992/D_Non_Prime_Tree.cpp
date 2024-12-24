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

// 0 -> 4  -> 8
// 0 -> 6  -> 10
// 0 -> 9  -> 13
// 0 -> 15 -> 19

void solve() {
    int n;std::cin >> n;
    std::vector adj(n, std::vector<int>());
    for (int i = 0;i < n - 1;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = -1;
    for (int i = 0;i < n;++i)
        if (adj[i].size() == 1)
            root = i;
    std::vector<int> ans(n);
    ans[root] = 2 * n - 1;
    int l = 2, r = 2 * n;
    auto dfs = [&](auto&& self, int u, int p, bool b)->void {
        if (b)ans[u] = r, r -= 2;
        else ans[u] = l, l += 2;
        for (int v : adj[u])if (v != p) {
            self(self, v, u, !b);
        }
        };
    dfs(dfs, adj[root][0], root, 1);
    for (auto x : ans)std::cout << x << ' ';
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