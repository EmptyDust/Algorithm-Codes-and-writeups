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
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector<int> g[n];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    i64 ans = 1e18, sum = std::accumulate(a.begin(), a.end(), 0ll);
    std::function<void(int)> dfs = [&](int u) {
        if (g[u].size() <= 1) {
            ans = std::min(ans, a[u]);
            return;
        }
        for (int v : g[u]) {
            a[v] += a[u];
            dfs(v);
        }
        };
    dfs(0);
    std::cout << sum - 2 * ans;
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