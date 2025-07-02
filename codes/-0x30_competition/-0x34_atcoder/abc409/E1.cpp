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
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector g(n, std::vector<a2>());
    for (int i = 1;i < n;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }
    i64 ans = 0;
    auto dfs = [&](auto&& self, int u, int p)->i64 {
        i64 cnt = a[u];
        for (auto [v, w] : g[u])if (v != p) {
            i64 res = self(self, v, u);
            ans += std::abs(res) * w;
            cnt += res;
        }
        return cnt;
        };
    dfs(dfs, 0, -1);
    std::cout << ans;
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