#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<u64> f(n + 1);
    for (int i = 1;i <= m;++i) {
        int u, v;std::cin >> u >> v;
        u64 x = rng();
        f[u] ^= x;
        f[v] ^= x;
    }
    for (int i = 1;i <= n;++i)
        f[i] ^= f[i - 1];
    std::map<u64, int> mp;
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        mp[f[i]]++;
        ans = std::max(ans, mp[f[i]]);
    }
    std::cout << n - ans;
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