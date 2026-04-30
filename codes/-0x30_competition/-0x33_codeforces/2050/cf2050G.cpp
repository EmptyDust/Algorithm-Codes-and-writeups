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
    for (int i = 0;i < n - 1;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    auto dfs = [&](auto&& self, int u, int p)->int {
        int max1 = 0, max2 = 0;
        for (auto v : adj[u])if (v != p) {
            int r = self(self, v, u);
            if (r > max1)std::swap(r, max1);
            if (r > max2)std::swap(r, max2);
        }
        ans = std::max(ans, (int)adj[u].size() + std::max(0, max1 - 1) + std::max(0, max2 - 1));
        return std::max(1, (int)adj[u].size() - (p != -1) + std::max(0, max1 - 1));
        };
    dfs(dfs, 0, -1);
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