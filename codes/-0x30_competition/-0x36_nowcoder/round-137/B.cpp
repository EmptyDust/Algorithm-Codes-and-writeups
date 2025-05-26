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
    int n, m;std::cin >> n >> m;
    std::vector g(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> f(n), d(n);
    auto dfs = [&](auto&& self, int u, int p)->void {
        if (p != -1)d[u] = d[p] + 1;
        f[u] = p;
        for (auto v : g[u])if (v != p)self(self, v, u);
        };
    dfs(dfs, 0, -1);
    std::vector<int> a(m);
    int minp = -1;
    for (auto& x : a) {
        std::cin >> x;x--;
        if (minp == -1 || d[x] < d[minp]) {
            minp = x;
        }
    }
    std::cout << m - 1 << '\n';
    for (auto& x : a)if (x != minp) {
        std::cout << x + 1 << ' ' << f[x] + 1 << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}