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
    int n, s, r1, r2;std::cin >> n >> s >> r1 >> r2;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cur = 0, curp = 0;
    std::function<void(int, int, int)> dfs = [&](int x, int p, int d) {
        if (d > cur) {
            curp = x;
            cur = d;
        }
        for (int v : adj[x])if (v != p) {
            dfs(v, x, d + 1);
        }
        };
    dfs(1, 0, 0);
    cur = 0;
    dfs(curp, 0, 0);
    // std::cout << cur << ' ' << curp << '\n';
    if (r1 * 2 < r2 && r1 * 2 < cur) {
        std::cout << "General_Kangaroo";
    }
    else {
        std::cout << "Kangaroo_Splay";
    }
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