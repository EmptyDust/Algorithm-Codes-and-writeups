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
    for (auto& x : a)std::cin >> x;
    std::vector adj(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector dp(n, std::vector<i64>(2));
    std::vector<int> size(n, 1);
    auto dfs = [&](auto&& dfs, int u, int p) ->void {
        dp[u][0] = 1;
        for (auto v : adj[u]) if (v != p) {
            dfs(dfs, v, u);
            std::vector<i64> ndp(size[u] + size[v] + 1);
            for (int a = 0;a <= size[u];++a) {
                for (int b = 0;b <= size[v];++b) {
                    ndp[a + b] = (ndp[a + b] + dp[u][a] * dp[v][b]) % mod;
                }
            }
            size[u] += size[v];
            dp[u] = ndp;
        }
        if (a[u] <= size[u]) {
            if (a[u]) dp[u][a[u]] = dp[u][a[u] - 1];
            else dp[u][a[u]] = 0;
        }
        };
    dfs(dfs, 0, -1);
    i64 ans = 0;
    for (auto x : dp[0]) ans = (ans + x) % mod;
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