#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using u64 = unsigned long long;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<i64> c(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> c[i];
    std::vector<u64> adj(n + 1), w(n + 1);
    for (int i = 1;i <= n;++i)w[i] = rng();
    for (int i = 0;i < m;++i) {
        i64 u, v;std::cin >> u >> v;
        adj[v] ^= w[u];
    }
    std::map<u64, i64> sums;
    for (int v = 1;v <= n;++v) {
        if (adj[v])
            sums[adj[v]] += c[v];
    }
    i64 gcd = -1;
    for (auto [_, sum] : sums) {
        if (gcd == -1)gcd = sum;
        else gcd = std::__gcd(gcd, sum);
    }
    std::cout << gcd;
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