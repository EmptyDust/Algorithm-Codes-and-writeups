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
    std::string s;std::cin >> s;
    std::vector adj(n, std::vector<int>());
    std::vector<int> d(n);
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    std::vector<int> a, res(n), vis(n);
    for (int i = 0;i < n;++i)
        if (d[i] == 1) {
            a.push_back(i);
            vis[i] = 1;
        }
    for (int i = 0;i < a.size();++i) {
        int u = a[i];
        for (auto v : adj[u]) if (d[v] > 0) {
            res[v] += s[u] != s[v];
            d[v]--;
            d[u]--;
            if (d[v] == 1 && res[v] == 0 && !vis[v]) {
                a.push_back(v);
                vis[v] = 1;
            }
            if (d[v] == 0 && res[v] <= 1 && !vis[v]) {
                a.push_back(v);
                vis[v] = 1;
            }
        }
    }
    std::cout << n - a.size();
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