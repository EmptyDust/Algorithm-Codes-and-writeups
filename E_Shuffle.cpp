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
    std::vector<std::vector<int>> adj(n);
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> match(n, -1);
    int ans = n;
    auto dfs = [&](auto&& self, int u, int p)->void {
        for (int v : adj[u]) {
            if (v == p)continue;
            self(self, v, u);
            if (match[u] == -1 && match[v] == -1) {
                match[u] = v;
                match[v] = u;
                ans--;
            }
        }
        };
    dfs(dfs, 0, -1);
    std::queue<int> q;
    std::vector<int> vis(n);
    for (int i = 0;i < n;++i)if (match[i] == -1) {
        q.push(i);
        vis[i] = 1;
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto y : adj[x]) {
            int z = match[y];
            if (!vis[z]) {
                vis[z] = 1;
                q.push(z);
            }
        }
    }
    for (int i = 0;i < n;++i) {
        if (!vis[i] && adj[i].size() == 1) {
            ans++;
            break;
        }
    }
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