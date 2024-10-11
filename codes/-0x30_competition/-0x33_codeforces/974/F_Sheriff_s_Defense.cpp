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
    int n, c;std::cin >> n >> c;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector adj(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::function<pii(int, int)> dfs = [&](int u, int p) ->pii {
        int sz = adj[u].size();
        pii ret = { 0,a[u] };
        for (int v : adj[u])if (v != p) {
            auto [t, d] = dfs(v, u);
            ret.first += std::max(t, d);
            ret.second += std::max(t, d - 2 * c);
        }
        return ret;
        };
    auto [a1, a2] = dfs(0, -1);
    std::cout << std::max(a1, a2);
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