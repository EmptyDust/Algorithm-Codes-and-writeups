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
    std::vector d(n, 0);
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }
    bool ans = true;
    for (int i = 0;i < n;++i) {
        int cnt = 0;
        for (int x : adj[i]) {
            if (d[x] >= 2)cnt++;
        }
        if (cnt > 2)ans = false;
    }
    std::cout << (ans ? "YES" : "NO");
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